# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 10:33:32 by floblanc          #+#    #+#              #
#    Updated: 2019/04/01 17:09:42 by floblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_NAME =	already_exist.c\
		extract_room.c\
		free_lst.c\
		is_valid.c\
		stock_data.c\
		main.c\
		make_matrix.c\
		write_data.c\
		ft_lstlen.c\

SRC_PATH = ./src

OBJ_PATH = ./obj

INC = -I./includes

LIB = libft/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 #\\\\\\\\\\\\\\\\\\G3////////////////////////

# Colors
_BLACK = $'\033[30m$'
_RED = $'\033[31m$'
_GREEN = $'\033[32m$'
_YELLOW = $'\033[33m$'
_BLUE = $'\033[34m$'
_PURPLE = $'\033[35m$'
_CYAN = $'\033[36m$'
_GREY = $'\033[37m$'
_END=$'\033[0m$'

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : lib $(NAME)

lib :
	@echo "\n\n"
	@echo "$(_GREEN)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "$(_YELLOW)|     COMPILING LIBFT    |$(_END)"
	@echo "$(_GREEN)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "\n\n"
	@make -C $(LIB) -j
	@cp libft/libft.a .
	@echo "$(_RED)[ LIBFT DONE ] $(_END)"

$(NAME) : lib $(SRC) $(OBJ_PATH) $(OBJ)
	@echo "\n\n"
	@echo "$(_GREEN)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "$(YELLOW)|    COMPILING LEM_IN    |$(_END)"
	@echo "$(_GREEN)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "\n\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a
	@echo "$(_RED)[ LEM_IN DONE ]$(_END)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean :
	@make clean -C $(LIB)
	@rm -rf $(OBJ_PATH)
	@echo "$(_RED)======< CLEAN PROJECT & LIBFT DONE >======$(_END)"
	@rm -f ./libft.a

fclean : clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)
	@echo "$(_RED)======< FCLEAN PROJECT & LIBFT DONE >======$(_END)"

re : fclean all

.PHONY : clean all $(NAME) fclean re lib
