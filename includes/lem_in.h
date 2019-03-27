/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:56:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/27 15:54:24 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/////////////////////
# include <stdio.h>//
/////////////////////

# include "../libft/libft.h"

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				startend;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

int					room_already_exist(t_room **begin, t_room *new);
int					link_already_exist(t_link **begin, t_link *new);
int					room_form_is_valid(char *str);
int					link_form_is_valid(char *str);
int					link_is_valid(t_link *new, t_room **begin);
int					command_is_valid(char *str);
int					valid_digit(char *line);
char				*extract_room_name(char *str);
int					extract_room_x(char *str, int *error);
int					extract_room_y(char *str, int *error);
void				free_lst_room(t_room **begin);
void				free_lst_link(t_link **begin);
void				stock_room(char *line, t_room **begin, int *startend,
		int *error);
void				new_link_maker(t_link *new, char *line, int i);
void				stock_link(char *line, t_link **begin, t_room **roombeg,
		int *error);
void				set_startend(char *line, int *startend, int *error);
void				read_n_stock(int *ant_n, t_room **roombeg,
		t_link **linkbeg);
void				coord_is_valid(char *coord, int *error);
int					check_startend(t_room **begin);
#endif
