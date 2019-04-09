/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:50:14 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/09 11:16:54 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	free_paths(t_path **begin)
{
	int i;
	int	j;
	t_path	*before;

	if (!(begin && *begin))
		return ;
	i = 1;
	while (*begin)
	{
		before = *begin;
		j = 0;
		while (j < i)
			free((*begin)->path[j++]);
		free((*begin)->len);
		i++;
		*begin = (*begin)->next;
		free(before);
		before = 0;
	}
}
