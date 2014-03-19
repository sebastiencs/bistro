/*
** header.h for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct 28 22:11:54 2013 chapui_s
** Last update Sun Nov 10 18:18:07 2013 chapui_s
*/

#ifndef HEADER_H_
# define HEADER_H_

typedef struct		s_pile_ops
{
  char			op;
  struct s_pile_ops	*next;
}			t_pile_ops;

typedef struct		s_pile_calc
{
  char			*nb;
  struct s_pile_calc	*next;
}			t_pile_calc;

typedef struct		s_board
{
  t_pile_ops		*pile_ops;
  t_pile_calc		*pile_calc;
  char			*base;
  char			*ops;
}			t_board;

typedef struct	s_mult
{
  char		*n1;
  char		*n2;
  size_t	size_n1;
  size_t	size_n2;
  char		neg;
  char		*base;
}		t_mult;

typedef struct	s_vars_div
{
  char		*tmp_n1;
  char		*tmp_n2;
  char		*save_tmp;
  char		*save_final;
}		t_vars_div;

typedef struct	s_vars_add
{
  int	size_nb1;
  int	size_nb2;
  int	size_res;
  char	*result;
  char	*base;
  char	*nb1;
  char	*nb2;
  char	neg;
}		t_vars_add;

t_pile_calc	*create_pile_calc(char *nb);
void		*add_begin_calc(t_pile_calc **pile_calc, char *nb);
t_pile_calc	*rm_first_calc(t_pile_calc **pile_calc);
t_pile_ops	*create_pile_ops(char op);
void		*add_begin_ops(t_pile_ops **pile_ops, char op);
t_pile_ops	*rm_first_ops(t_pile_ops **pile_ops);
void		*manage_ops(char op, t_board *board);
char		*inf_add(char *n1, char *n2, char *base, char neg);
void		*manage_close_parent(t_board *board);
char		*do_op(char *nb1, char op, char *nb2, t_board *board);
char		*inf_mult(char *n1, char *n2, char *base, char neg);
char		*inf_sub(char *n1, char *n2, char *base, char neg);
void		reverse_calc(t_pile_calc **begin_list);
void		reverse_ops(t_pile_ops **begin_list);
char		*inf_div(char *n1, char *n2, char *base, char neg);
void		clean_nbs(char *n1, char *n2, char *base);
char		*add_minus(char *result, char neg);
char		*inf_mod(char *n1, char *n2, char *base, char neg);
char		*check_sintax(char *str, t_board *board, char *ops, unsigned int size);
char		*my_malloc(size_t size);
int		get_id(char c, char *base);
void		my_putchar(char c);
unsigned int	my_strlen(char *str);
void		my_putstr(char *str);
int		c_to_i(char c, char *base);
unsigned int	my_atoi(char *str);
int		check_number(char *base, char *str, size_t i, t_board *board);
int		is_ope(char *ops, char c);
int		is_number(char *base, char c);
void		prepare_tmp(int *tmp, size_t size);
void		prepare_res(char *result, char *base, size_t size);
int		is_it_nb(char c, char *base);
char		*ret_simple(char *base, int nb, int negativ, char neg);
int		*do_inf_sub(char *n1, char *n2, char *base, int ret);
void		*little_calc(t_board *board);
void		*little_rev_calc(t_board *board);
void		*before_save_nb(char *expr, unsigned int *i, t_board *board);
char		check_base_opr(char *expr, t_board *board, char *opr, unsigned int size);
char		*rm_spaces(char *str, t_board *board, char *ops);
int		is_nbs_after_last_op(unsigned int i, char *str, char *base, char *ops);
void		free_tmps(t_vars_div *vars);

#endif
