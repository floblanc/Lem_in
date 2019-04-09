/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:53:46 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:44:53 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	falsepc3(const char *str, int *i, int *moins, int *zero)
{
	while (ft_isdigit(str[*i]) || ft_strsearch("-+0# lhjz*$L.", str[*i]))
	{
		if (str[*i] == '-')
			*moins = 1;
		else if (str[*i] == '0')
			*zero = 1;
		(*i)++;
	}
}

void	falsepc2(const char *str, int *i, int *moins, int *zero)
{
	while (ft_strsearch("-+0# lhjz*$L.", str[*i]))
	{
		if (str[*i] == '-')
			*moins = 1;
		else if (str[*i] == '0')
			*zero = 1;
		(*i)++;
	}
}

int		falsepc(int i, const char *str, int *ret)
{
	int		ok;
	int		zero;
	int		moins;

	moins = 0;
	zero = 0;
	i++;
	ok = 1;
	falsepc2(str, &i, &moins, &zero);
	if (ft_isdigit(str[i]))
		ok = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	falsepc3(str, &i, &moins, &zero);
	if (zero && moins == 0 && ok > 1)
		printpreci(ok - 1);
	else if (moins == 0 && ok > 1)
		printdc(ok - 1);
	if (str[i] != '\0')
		write(1, &str[i], 1);
	if (moins == 1 && ok > 1)
		printdc(ok - 1);
	if (str[i])
		*ret += ok;
	return (i + 1);
}

void	ft_printf2(const char *format, int *i, int j, va_list ap)
{
	if (format[i[0]] == '%')
	{
		if ((j = is_valide((char*)format, i[0] + 1)))
		{
			i[0] = analyse((char*)format, i, j, ap) + 1;
			i[2] = i[2] + i[1];
		}
		else
			i[0] = falsepc(i[0], format, &(i[2]));
	}
	else
	{
		if (format[i[0]] != 0)
			write(1, &format[i[0]], 1);
		i[2]++;
		i[0]++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		*i;
	int		j;
	int		res;

	if (!(i = (int*)malloc(sizeof(int) * 3)))
		return (0);
	va_start(ap, format);
	i[0] = 0;
	i[2] = 0;
	while (i[0] < (int)ft_strlen(format))
	{
		j = 0;
		ft_printf2(format, i, j, ap);
	}
	res = i[2];
	va_end(ap);
	free(i);
	return (res);
}
