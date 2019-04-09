/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:45:26 by maginist          #+#    #+#             */
/*   Updated: 2019/04/09 19:29:26 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		find_path(int **matrix, t_room *tab, t_path *new)
{
	/*
	 *HYPOTHESES : (usefull or useless that is the question)
	 *
	 * path_n dans la structure t_path? (ca me fait chier de la promener partout)
	 * et/ou envoyer new en ayant copie best (avec un chemin en plus) 
	 * pour pouvoir demarrer sur cette base (mais pouvoir le modifier quand meme)
	 *
	 * tab[].taken == i => i - 1 == index path
	 * ex: taken = 1 => pris par le chemin path[0]
	 * 	   taken = 2 => pris par le chemin path[1]
	 * 	   etc...
	 *
	 * 	   calcul pout savoir si un autre chemin est possible en fonction du nombre de
	 * 	   salles et de la len du chemin le plus court et de la somme des rooms
	 * 	   deja use (mettre un return pour signaler si la limite est atteinte?
	 * 	   ou a mettre dans le main3 ou fonction tierce?)
	 * 	   hypothetique condition pour le while du main3 l-39 : 
	 *	(i++ > path_n && "size" - "somme des len des chemins precedemment stockes" > "len du chemin le plus long trouve precedemment") 
	 *
	 *	PS: sinon on commence a coder l'algo et on voit ensuite
	 *	(histoire de pas perdre de temps sur des outils inutiles)
	 */
	int	i;

	i = 0;
	while (i < path_n)
	{

		i++;
	}
}
