# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maginist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 11:22:24 by maginist          #+#    #+#              #
#    Updated: 2019/05/14 17:36:48 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME =already_exist.c\
		  extract_room.c\
		  find_path.c\
		  free_lst.c\
		  is_valid.c\
		  main.c\
		  make_matrix.c\
		  paths_utils.c\
		  put_wth.c\
		  stock_data.c\
		  utils.c\
		  write_data.c\
		  other_utils.c\
		  other_path.c\
		  init_struct.c\

SRC_PATH = ./src

OBJ_PATH = ./obj

INC = -I./includes

LIB = libprintf/

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3 #\\\\\\\\\\\\\\\\\\G3////////////////////////

# Colors
CK = $'\033[30m$'
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
	@make -C $(LIB) -j
	@cp libprintf/libprintf.a .
	@echo "$(_GREEN)[ LIBPRINTF DONE ]$(_END)"

$(NAME) : lib $(SRC) $(OBJ_PATH) $(OBJ)
	@echo "\n"
	@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "|    COMPILING LEM_IN    |"
	@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
	@echo "\n"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libprintf/libprintf.a
	@echo "$(_GREEN)[ LEM_IN DONE ]$(_END)"

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $? $(INC) -o $@

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean :
	@make clean -C $(LIB)
	@rm -rf $(OBJ_PATH)
	@echo "$(_BLUE)======< CLEAN PROJECT & LIBPRINTF DONE >======$(_END)"
	@rm -f ./libprintf.a

fclean : clean
	@make fclean -C $(LIB)
	@rm -f $(NAME)
	@echo "$(_BLUE)======< FCLEAN PROJECT & LIBPRINTF DONE >======$(_END)"

re : fclean all

.PHONY : clean all $(NAME) fclean re lib
