# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpenney <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 14:21:35 by dpenney           #+#    #+#              #
#    Updated: 2019/11/27 18:35:39 by dpenney          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC := fp_type.h \
	   conv_other.c \
	   arg_extractors.c \
	   arg_extractors2.c \
	   conv_wrappers_other.c \
	   find_action.c \
	   printf.c \
	   read_spec.c  \
	   read_spec_util.c \
	   printf.h	\
	   conv_int.c \
	   conv_wrappers_int.c\
	   apply_spec.c \
	   apply_spec_util.c \
	   apply_spec_util2.c \
	   apply_spec_util3.c \
	   apply_spec_util4.c \
	   ftoa.c \

OBJ = $(SRC:.c = o)

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc -g $(SRC) -Wall -Wextra -c -I . -I libft/includes -L ./libft -lft  -DMAC_OS
	@ar rc libftprintf.a *.o ./libft/*.o
	@ranlib $(NAME)
	@echo "\n\n\nIt's done! Use it  ( ͡° ͜ʖ ͡°( ͡❛ ͜ʖ ͡❛)  \n\n\n"

clean:
	@rm -f *.o
	@rm -f ./libft/*.o

fclean: clean
	@rm -f libftprintf.a
	@rm -f ./libft/libft.a

re: fclean all

.PHONY: all clean fclean re $(NAME)
