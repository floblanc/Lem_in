# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 10:33:32 by floblanc          #+#    #+#              #
#    Updated: 2019/03/27 14:25:15 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_NAME =	already_exist.c\
		extract_room.c\
		free_lst.c\
		is_valid.c\
		stock_data.c\
		main.c\

SRC_PATH = ./src

OBJ_PATH = ./obj

INC = -I./includes

LIB = libft/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

_UNDER=$'\x1b[4m$'

_GREEN=$'\x1b[32m$'

_YELLOW=$'\x1b[33m$'

_RED=$'\x1b[31m$'

_WHITE=$'\x1b[37m$'

_END=$'\x1b[0m$'

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : lib $(NAME)

lib :
	@echo "\n\n"
	@echo "$(_GREEN)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "$(YELLOW)|     COMPILING LIBFT    |$(_END)"
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
