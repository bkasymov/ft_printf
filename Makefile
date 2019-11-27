# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpenney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 14:21:35 by dpenney           #+#    #+#              #
#    Updated: 2019/11/25 15:47:14 by dpenney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC := arg_extractors.c \
	   conv_other.c \
	   conv_wrappers_other.c \
	   find_action.c \
	   printf.c \
	   read_spec.c  \
	   read_spec_util.c \
	   printf.h	\
	   conv_int.c \
	   conv_wrappers_int.c\
	   apply_spec.c \
	   ftoa.c \

OBJ = $(SRC:.c = o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -g $(SRC) -Wall -Wextra -c -I . -I libft/includes -L ./libft -lft  -DMAC_OS
	@ar rc libftprintf.a *.o ./libft/*.o
	@ranlib $(NAME)
	@echo "\n\n\nIt's done! Use it  ¯\_(ツ)_/¯ \n\n\n"

clean:
	@rm -f *.o
	@rm -f ./libft/*.o

fclean: clean
	@rm -f libftprintf.a
	@rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re $(NAME)
