/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:07:55 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:50:19 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == 0)
		return ((char*)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == c)
			return ((char*)s + i);
		i++;
	}
	return (0);
}
