P_ROOT := ../../
SRC := arg_extractors.c \
	   conv_other.c \
	   conv_wrappers_other.c \
	   find_action.c \
	   printf.c \
	   read_spec.c  \
	   printf.h	\
	   read_spec.h \
	   conv_int.c \
	   conv_wrappers_int.c
SRC		:= $(addprefix $(P_ROOT)/,$(SRC))
all:
	make -C $(P_ROOT)libft
	make -C $(P_ROOT)
	gcc -o test -g $(SRC) main.c -I $(P_ROOT) -I $(P_ROOT)libft/includes -L $(P_ROOT)libft -lft
