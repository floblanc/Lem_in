/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:32:22 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:52:29 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (0);
		while (s[i])
		{
			str[i] = f(s[i]);
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
