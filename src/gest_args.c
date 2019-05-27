/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gest_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:08:54 by floblanc          #+#    #+#             */
/*   Updated: 2019/05/27 12:09:54 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	stock_and_print_step(int write, int best_step)
{
	static int	steps;

	if (!(steps))
		steps = 0;
	if (best_step > 0)
		steps = best_step;
	if (write)
		ft_printf("\nNumber of steps : %d\n", steps);
}

int		check_args(int ac, char **av, int *arg_used)
{
	if (ac == 1)
		return (1);
	if (ft_strcmp(av[1], "-h") == 0)
	{
		ft_printf
			return (0);
	}
	else if (ft_strcmp(av[1], "-m") == 0)
		*arg_used = 1;
	else if (ft_strcmp(av[1], "-s") == 0)
		*arg_used = 2;
	else
	{
		ft_printf("Wrong Argument\n");
		return (0)
	}
	return (1);
}
