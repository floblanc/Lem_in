/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:25:00 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:54:45 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	checker;
	unsigned int	runner;

	runner = 0;
	checker = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[runner])
	{
		if (haystack[runner] == needle[checker])
			checker++;
		else
		{
			runner -= checker;
			checker = 0;
		}
		runner++;
		if (checker == ft_strlen(needle))
			return ((char*)haystack + runner - checker);
	}
	return (0);
}
