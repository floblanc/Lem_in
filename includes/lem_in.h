/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:56:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 12:49:44 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

///////////////////
# include <stdio.h>
///////////////////

# include "../libft/libft.h"

typedef	struct		s_room
{
	char			*name;
	float			x; //char???
	float			y; //char???
	int				start;
	int				end;
	struct	s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char 			*name1;
	char			*name2;
	struct	s_stock	*next;
}					t_link;

int					room_form_is_valid(char *str, t_link **begin);
int					link_form_is_valid(char *str);
int					command_is_valid(char *str, t_link **begin);
void				read_n_stock(t_room **roombeg, t_link **linkbeg);
void				stock_room(char *line, t_room **begin, int *startend, int *error);
void				stock_link(char *line, t_room **beggin, int *startend, int *error);
void				check_command(char *line, int *startend, int *error);

#endif
