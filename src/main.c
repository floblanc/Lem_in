/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 10:11:04 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/27 15:37:24 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		main(void)
{
	int		ant_n;
	t_room	*roombeg;
	t_link	*linkbeg;

	ant_n = 0;
	roombeg = 0;
	linkbeg = 0;
	read_n_stock(&ant_n, &roombeg, &linkbeg);
	printf("%d\n", ant_n);
	while (roombeg)
	{
		if (roombeg->startend == 1)
			printf("##start\n");
		else if (roombeg->startend == 2)
			printf("##end\n");
		printf("%s %d %d\n", roombeg->name, roombeg->x, roombeg->y);
		roombeg = roombeg->next;
	}
	while (linkbeg)
	{
		printf("%s-%s\n", linkbeg->name1, linkbeg->name2);
		linkbeg = linkbeg->next;
	}
	return (0);
}
