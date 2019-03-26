/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 12:19:34 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 12:49:46 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	extract_room_name(char *str)
{
	char	*name;
	int		i;

	name = 0;
	i = 0;
	if (!(str))
		return (0);
	while (ft_isalnum(str[i]))
		i++;
	if (!(name = ft_strdup(stri)))
		exit (0);
	return (name);
}
