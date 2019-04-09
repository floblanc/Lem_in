/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:09:41 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:54:56 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (s)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
			return (0);
		while (i < len)
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (0);
}
