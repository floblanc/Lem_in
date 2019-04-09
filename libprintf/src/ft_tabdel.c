/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maginist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:24:17 by maginist          #+#    #+#             */
/*   Updated: 2019/04/04 11:55:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_tabdel(char **tab)
{
	int	i;

	i = 0;
	if (!(tab))
		return ;
	while (tab[i])
	{
		ft_memdel((void*)&tab[i]);
		i++;
	}
	free(tab);
}
