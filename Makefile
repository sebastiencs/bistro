##
## Makefile for bistro in /home/chapui_s/travaux/bistro
## 
## Made by chapui_s
## Login   <chapui_s@epitech.net>
## 
## Started on  Wed Nov  6 12:42:03 2013 chapui_s
## Last update Wed Mar 19 11:32:59 2014 chapui_s
##

SRC	=	main.c \
		my_putchar.c \
	  	my_putstr.c \
		my_strlen.c \
		ops.c \
		inf_add.c \
		inf_mult.c \
		inf_div.c \
		inf_mod.c \
		inf_sub.c \
		pile_calc.c \
		pile_ops.c \
		check_syntax.c \
		get_id.c \
		c_to_i.c \
		my_atoi.c \
		check_number.c \
		is_eval.c \
		eval_expr.c \
		inf_add_fct.c \
		inf_sub_fct.c \
		inf_mult_fct.c \
		inf_div_fct.c \
		my_malloc.c \
		eval_expr_fct.c \
		little_calc.c \
		check_base_syntax.c \
		check_syntax_fct.c \
		check_syntax_fct2.c

NAME	= calc

OBJ	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -rf

all:	 $(NAME)


$(NAME):	$(OBJ)
	$(CC) -O3 -o $(NAME)  $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
