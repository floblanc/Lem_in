/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:54:09 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/29 11:55:04 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_lstlen(t_room **begin)
{
	int		size;
	t_room	*current;

	size = 0;
	if (*begin)
	{
		current = *begin;
		while (current)
		{
			size++;
			current = current->next;
		}
	}
	return (size);
}
