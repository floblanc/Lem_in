/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:58:17 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 11:56:44 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

static void	arrondi2(char *num, char *tmp, t_data *data)
{
	data->size_aff += 1;
	data->tdc -= 1;
	tmp = ft_strdup(num);
	ft_strcpy(num + 1, tmp);
	num[0] = '1';
	free(tmp);
}

static void	arrondi1(char *num, int *i, char *tmp, int *check)
{
	if (num[0] == '+' || num[0] == ' ')
		(*i)++;
	if ((*i) > 0 && (num[(*i)] == '.' || num[(*i)] == '\0'))
		(*i)--;
	if ((*check) > (int)ft_strlen(tmp))
		(*check) = 0;
}

static void	arrondi(char *num, char *tmp, t_data *data, int check)
{
	static int	retenue;
	int			i;

	if ((int)ft_strlen(num) < data->size_aff)
		return ;
	if (!(retenue))
		retenue = 0;
	if (check <= (int)ft_strlen(tmp) && tmp[check] == '.')
		check++;
	i = check - 1;
	arrondi1(num, &i, tmp, &check);
	if ((check >= data->size_aff && tmp[check] >= '5' && tmp[check] <= '9')
			|| (i >= 0 && ft_isdigit(num[i]) && retenue == 1))
	{
		if (num[i] < '9')
			num[i] += 1;
		else
		{
			num[i] = '0';
			retenue = 1;
			arrondi(num, tmp, data, i);
		}
	}
	else if (retenue == 1)
		arrondi2(num, tmp, data);
}

static char	*ajust_num(char *num, t_data *data, int i, char *tmp)
{
	free(num);
	if (!(num = ft_strnew(data->size_aff + 1)))
		return (0);
	if (tmp[0] != '-')
	{
		if (data->plus == 1)
		{
			num[0] = '+';
			i = 1;
		}
		else if (data->space == 1)
		{
			num[0] = ' ';
			i = 1;
		}
	}
	ft_strncpy(num + i, tmp, (size_t)(data->size_aff));
	i = ft_strlen(num);
	arrondi(num, tmp, data, i);
	if (data->size_aff - i - data->preci - 1 == 0 && data->preci > 0)
		num[i++] = '.';
	while (i < data->size_aff)
		num[i++] = '0';
	free(tmp);
	return (num);
}

void		gest_f(t_data *data, va_list ap)
{
	char		*num;
	int			i;
	char		*tmp;

	i = 0;
	if (data->nb_flgs == 0 || (data->nb_flgs == 1 && data->flgs == 'l'))
		num = ftoa(va_arg(ap, double));
	else
		num = fltoa(va_arg(ap, long double));
	if (data->preci == -1)
		data->preci = 6;
	while (num[i] != '.' && num[i] != '\0')
	{
		data->size_aff += 1;
		i++;
	}
	if (data->preci > 0)
		data->size_aff += data->preci + 1;
	if ((data->plus == 1 || data->space == 1) && num[0] != '-')
		data->size_aff += 1;
	data->tdc -= data->size_aff;
	if (!(tmp = ft_strdup(num)))
		return ;
	num = ajust_num(num, data, 0, tmp);
	gest_allnum(num, data);
}
