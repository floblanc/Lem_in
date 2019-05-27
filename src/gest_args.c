/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:08:54 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/27 17:20:08 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		print_matrix(int ***matrix, int size, t_write **str, t_room **tab)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\nMATRIX :\n");
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_printf("\t%d", (*matrix)[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
	free_room_tab(tab, size);
	free_matrix(matrix, size);
	free_lst_write(str);
	return (0);
}

void	help(void)
{
	ft_printf("Usage: ./lem-in -argument (only one arg or none) < map\n\n");
	ft_printf("ARGUMENT:\t\t\t\tMAP PROTOTYPE:\n");
	ft_printf("-m : print only matrix\t\t\t\tant number: <int > 0>\n");
	ft_printf("-s : print number of steps\t\t\troom: <name> <int> <int>\n");
	ft_printf("-h : help for command\t\t\t\tlink: <name1>-<name2>\n");
}

void	stock_and_print_step(int write, int best_step)
{
	static int	steps;

	if (!(steps))
		steps = 0;
	if (best_step > 0)
		steps = best_step;
	if (write && steps)
		ft_printf("\nNumber of steps : %d\n", steps);
}

int		check_args(int ac, char **av, int *arg_used)
{
	if (ac == 1)
		return (1);
	if (ac > 2)
	{
		ft_printf("Too many arguments\n");
		return (0);
	}
	if (ft_strcmp(av[1], "-h") == 0)
	{
		help();
		return (0);
	}
	else if (ft_strcmp(av[1], "-m") == 0)
		*arg_used = 1;
	else if (ft_strcmp(av[1], "-s") == 0)
		*arg_used = 2;
	else
	{
		ft_printf("Wrong Argument\n");
		return (0);
	}
	return (1);
}
