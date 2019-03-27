# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: floblanc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/12 10:09:35 by floblanc          #+#    #+#              #
#    Updated: 2019/03/27 12:10:09 by floblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_PATH = ./obj

SRC_PATH = ./src

SRC_NAME = ft_memset.c\
	   ft_bzero.c\
	   ft_memcpy.c\
	   ft_memccpy.c\
	   ft_memmove.c\
	   ft_memchr.c\
	   ft_memcmp.c\
	   ft_strlen.c\
	   ft_strdup.c\
	   ft_strndup.c\
	   ft_strcpy.c\
	   ft_strncpy.c\
	   ft_strcat.c\
	   ft_strncat.c\
	   ft_strlcat.c\
	   ft_strchr.c\
	   ft_strrchr.c\
	   ft_strstr.c\
	   ft_strnstr.c\
	   ft_strcmp.c\
	   ft_strncmp.c\
	   ft_atoi.c\
	   ft_atol.c\
	   ft_isalpha.c\
	   ft_isdigit.c\
	   ft_isalnum.c\
	   ft_isascii.c\
	   ft_isprint.c\
	   ft_toupper.c\
	   ft_tolower.c\
	   ft_memalloc.c\
	   ft_memdel.c\
	   ft_strnew.c\
	   ft_strdel.c\
	   ft_strclr.c\
	   ft_striter.c\
	   ft_striteri.c\
	   ft_strmap.c\
	   ft_strmapi.c\
	   ft_strequ.c\
	   ft_strnequ.c\
	   ft_strsub.c\
	   ft_strjoin.c\
	   ft_strtrim.c\
	   ft_strsplit.c\
	   ft_itoa.c\
	   ft_putchar.c\
	   ft_putstr.c\
	   ft_putendl.c\
	   ft_putnbr.c\
	   ft_putchar_fd.c\
	   ft_putstr_fd.c\
	   ft_putendl_fd.c\
	   ft_putnbr_fd.c\
	   ft_lstnew.c\
	   ft_lstdelone.c\
	   ft_lstdel.c\
	   ft_lstadd.c\
	   ft_lstiter.c\
	   ft_lstmap.c\
	   ft_tabdel.c\
	   ft_puttab.c\
	   ft_strsearch.c\
	   ft_tab3size.c\
	   ft_abs.c\
	   get_next_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

INC = libft.h

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all : $(NAME)

$(NAME) : $(OBJ_PATH) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $? -o $@ -I.

clean :
	@rm -rf $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all $(NAME) clean fclean re
