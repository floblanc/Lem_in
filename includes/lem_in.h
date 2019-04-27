/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:56:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/27 11:21:17 by floblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/////////////////////
# include <stdio.h>//
/////////////////////

# include "../libprintf/include/libprintf.h"

typedef	struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				startend;
	int				wth;
	int				taken;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

typedef	struct		s_write
{
	char			*str;
	struct s_write	*next;
}					t_write;

typedef	struct		s_path
{
	int				**path;
	int				*len;
	int				step;
	int				path_n;
	struct s_path	*next;
}					t_path;

int					room_already_exist(t_room **begin, t_room *new
		, t_room **end);
int					link_already_exist(t_link **begin, t_link *new);
int					room_form_is_valid(char *str);
int					link_form_is_valid(char *str);
int					ft_lstlen(t_room **begin);
int					check_startend(t_room **begin);
int					link_is_valid(t_link *new, t_room **begin);
int					command_is_valid(char *str);
int					valid_digit(char *line);
void				set_matrix(t_room *tab, t_write **str, int size, int ***matrix);
char				*extract_room_name(char *str);
int					extract_room_x(char *str, int *error);
int					extract_room_y(char *str, int *error);
int					fill_matrix(t_room *tab, int **matrix, char *str, int size);
int					fill_matrix2(t_room *tab, char *str, int **matrix, int i);
void				free_lst_room(t_room **begin);
void				free_lst_link(t_link **begin);
void				free_lst_write(t_write **begin);
void				free_room_tab(t_room **tab, int size);
void				free_matrix(int ***matrix, int size);
void				read_n_stock(int *ant_n, t_room **room, t_write **str);
void				stock_to_write(char *line, t_write **begin);
void				rooms_in_tab(t_room **tab, t_room **begin);
void				write_data(t_write **begin);
void				init_t_path(t_path **struc, int size, int t_path_n);
int					find_path(int **matrix, t_room *tab, t_path **new
		, int size);
int					calc_step(t_path *struc, int ant_n, int path_n);
void				put_wth(int **matrix, int i, int j, t_room *tab);
int					calc_size(t_room *tab);
void				free_paths(t_path **begin);
void				use_path(t_path *best, t_room *tab, int size);
void				write_path(t_path *best, t_room *tab, int j, int ant_n);
void				copy_best(t_path *best, t_path *new, int size, t_room *tab);
int					enougth_room_for_more(t_path *best, t_room *tab);
void				clean_some_taken(t_room *tab, int size, int symb);
void				try_swap_t_path(t_path **another_new, t_path **new
		, t_room *tab);
void				onelink_startend(int ant_n);
int					other_turn(int **matrix, t_room *tab, int *way, int room_n);

#endif
