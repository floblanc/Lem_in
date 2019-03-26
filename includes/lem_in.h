/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:56:50 by floblanc          #+#    #+#             */
/*   Updated: 2019/03/26 19:16:41 by floblanc         ###   ########.fr       */
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
	int			x;
	int			y;
	int				startend;
	struct s_room	*next;
}					t_room;

typedef	struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_stock	*next;
}					t_link;

int					room_form_is_valid(char *str);
int					link_form_is_valid(char *str);
int					command_is_valid(char *str);
void				read_n_stock(t_room **roombeg, t_link **linkbeg);
void				stock_room(char *line, t_room **begin, int *startend, int *error);
void				stock_link(char *line, t_link **begin, t_room **roombeg, int *error);
void				check_command(char *line, int *startend, int *error);
int				only_digit(char *line);
char				extract_room_name(char *str);
int				extract_room_x(char *str);
int				extract_room_y(char *str);
#endif
