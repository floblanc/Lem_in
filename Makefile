# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 10:33:32 by floblanc          #+#    #+#              #
#    Updated: 2019/03/25 11:41:31 by floblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in

SRC_NAME =

SRC_PATH = ./src

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = ./obj

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC = -I./includes

LIB = libft/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : lib $(NAME)

lib :
	make -C $(LIB) -j

$(NAME) : lib $(INC) $(SRC) $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) libft/libft.a

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	$(CC) $(CFLAGS) -c $? $(INC) -o $@

$(OBJ_PATH):
		mkdir -p $(OBJ_PATH)

clean :
	make clean -C $(LIB)
	rm -rf ./obj

fclean : clean
	make fclean -C $(LIB)
	rm -f $(NAME)

re : fclean all
