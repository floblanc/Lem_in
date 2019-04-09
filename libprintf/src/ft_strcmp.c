/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:30:36 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:50:38 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (c1[i] == c2[i] && c1[i] != '\0' && c2[i] != '\0')
		i++;
	return (c1[i] - c2[i]);
}
