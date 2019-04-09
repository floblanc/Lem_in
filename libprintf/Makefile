# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maginist <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 09:46:56 by maginist          #+#    #+#              #
#    Updated: 2019/04/04 14:26:51 by maginist         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

FILES = add_pre_flgs.c\
	  analyse.c\
	  fillbegin.c\
	  ft_printf.c\
	  gest_allnum.c\
	  gest_b.c\
	  gest_majx.c\
	  gest_o.c\
	  gest_u.c\
	  gest_x.c\
	  gest_c.c\
	  gest_di.c\
	  gest_p.c\
	  gest_s.c\
	  gest_f.c\
	  gest_pc.c\
	  gest_r.c\
	  init_struct.c\
	  newstart_cleanbegin.c\
	  printdc.c\
	  redirection.c\
	  stock_digit.c\
	  stock_flgs.c\
	  bulltoa.c\
	  bultoa.c\
	  bustoa.c\
	  butoa.c\
	  buctoa.c\
	  lltoa.c\
	  ltoa.c\
	  stoa.c\
	  ctoa.c\
	  uctoa.c\
	  ulltoa.c\
	  ultoa.c\
	  ustoa.c\
	  utoa.c\
	  ftoa.c\
	  fltoa.c\
	  printpreci.c\
	  is_valide.c\
	  ft_memset.c\
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
	  get_next_line.c\
	  get_next_line_mod.c

# Colors
_RED = $'\033[31m$'
_GREEN = $'\033[32m$'
_YELLOW = $'\033[33m$'
_BLUE = $'\033[34m$'
_END=$'\033[0m$'

OBJ_PATH = ./obj

SRC_PATH = ./src

OBJ_NAME = $(FILES:.c=.o)

CC = gcc

INC = -I./include

CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix $(SRC_PATH)/,$(FILES))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
		@echo "\n\n"
		@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
		@echo "|     COMPILING LIBFT    |"
		@echo "$(_RED)|_-_-_-_-_-_-_-_-_-_-_-_-|$(_END)"
		@echo "\n\n"
		@ar rcs $(NAME) $(OBJ)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
		@$(CC) $(CFLAGS) -c $? -o $@ $(INC)

clean:
		@rm -rf ./obj

$(OBJ_PATH):
		@mkdir -p $(OBJ_PATH)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY : all $(NAME) clean fclean re
