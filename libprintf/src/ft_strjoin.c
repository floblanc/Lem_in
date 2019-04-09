/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 12:22:35 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:51:55 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	if (s1 && s2)
	{
		len = -1;
		if (!(str = (char*)malloc(sizeof(char) *
						(ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (0);
		while (s1[++len])
			str[len] = s1[len];
		i = 0;
		while (s2[i])
		{
			str[len + i] = s2[i];
			i++;
		}
		str[len + i] = '\0';
		return (str);
	}
	else
		return (0);
}
