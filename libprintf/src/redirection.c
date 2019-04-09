/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 15:34:30 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 12:03:18 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	init_tab_symb(t_fct *fct_tab)
{
	fct_tab[0].symbol = 'c';
	fct_tab[1].symbol = 's';
	fct_tab[2].symbol = 'p';
	fct_tab[3].symbol = 'd';
	fct_tab[4].symbol = 'i';
	fct_tab[5].symbol = 'o';
	fct_tab[6].symbol = 'u';
	fct_tab[7].symbol = 'x';
	fct_tab[8].symbol = 'X';
	fct_tab[9].symbol = 'b';
	fct_tab[10].symbol = '%';
	fct_tab[11].symbol = 'f';
	fct_tab[12].symbol = 'r';
}

void	init_tab_fct(t_fct *fct_tab)
{
	fct_tab[0].f = gest_c;
	fct_tab[1].f = gest_s;
	fct_tab[2].f = gest_p;
	fct_tab[3].f = gest_di;
	fct_tab[4].f = gest_di;
	fct_tab[5].f = gest_o;
	fct_tab[6].f = gest_u;
	fct_tab[7].f = gest_x;
	fct_tab[8].f = gest_majx;
	fct_tab[9].f = gest_b;
	fct_tab[10].f = gest_pc;
	fct_tab[11].f = gest_f;
	fct_tab[12].f = gest_r;
}

void	redirection(t_data *data, va_list ap)
{
	int		i;
	t_fct	fct_tab[13];

	i = 0;
	init_tab_symb(fct_tab);
	init_tab_fct(fct_tab);
	if (ft_strsearch("DOUF", data->symbol))
	{
		data->nb_flgs = 1;
		data->flgs = 'l';
		data->symbol = data->symbol - 'A' + 'a';
	}
	while (fct_tab[i].symbol)
	{
		if (fct_tab[i].symbol == data->symbol)
		{
			fct_tab[i].f(data, ap);
			return ;
		}
		i++;
	}
}
