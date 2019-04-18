/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:37:38 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/18 18:55:11 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	again_another_way(int **matrix, t_room *tab, t_path **new, int size)
{
	int			i;
	int			j;
	static int	only_one;
	t_path	*another_new;

	if (!(only_one) || only_one != (*new)->path_n)
		only_one = (*new)->path_n;
	else
		return ;
	//	printf("TRY ANOTHER\n");
	i = 0;
	another_new = 0;
	init_t_path(&another_new, size, (*new)->path_n);
	clean_some_taken(tab, size);
	while (i < (*new)->path_n)
	{
		j = 0;
		while (matrix[(*new)->path[i][j]][(*new)->path[i][j]] < 3
				&& (*new)->path[i][j] != 1)
		{
	//		printf("tab[%d](%s) j = %d\n", (*new)->path[i][j], tab[(*new)->path[i][j]].name, j);
			another_new->path[i][j] = (*new)->path[i][j];
			tab[(*new)->path[i][j]].taken = i + 1;
			j++;
		}
		another_new->path[i][j] = (*new)->path[i][j];
		tab[(*new)->path[i][j]].taken = i + 1;
		if ((*new)->path[i][j] != 1)
			j++;
		another_new->path[i][j] = (*new)->path[i][j];
		//		printf("tab[%d](%s).taken = -%d\n", another_new->path[i][j], tab[another_new->path[i][j]].name, i + 1);
		tab[another_new->path[i][j]].taken = (i + 1) * -1;
		another_new->path[i][j] = 0;
		i++;
	}
	if (find_path(matrix, tab, &another_new, size))
		try_swap_t_path(&another_new, new, tab);
	else
	{
		i = 0;
		j = 0;
		while (i < (*new)->path_n)
		{
			j = 0;
			while ((*new)->path[i][j] != 1)
				tab[(*new)->path[i][j++]].taken = i + 1;
			i++;
		}
	}
	free_paths(&another_new);// si on free dans le vide ca viens de la je pense
	return ;
}
