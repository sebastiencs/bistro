/*
** eval_expr.c for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct 28 17:09:15 2013 chapui_s
** Last update Sun Nov 10 19:29:43 2013 lowik_denel
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "header.h"

void	*calculate_pile(t_board *board)
{
  char	*tmp;
  void	*test_malloc;

  if (board->pile_ops)
  {
    test_malloc = little_calc(board);
    if (test_malloc == NULL)
      return (NULL);
  }
  reverse_calc(&(board->pile_calc));
  reverse_ops(&(board->pile_ops));
  while (board->pile_calc->next || board->pile_ops)
  {
    while (board->pile_ops
	   && board->pile_ops->op == board->ops[OP_OPEN_PARENT_IDX])
      rm_first_ops(&(board->pile_ops));
    test_malloc = little_rev_calc(board);
    if (test_malloc == NULL)
      return (NULL);
  }
  return ("1");
}

int	is_unary_minus(char *str, unsigned int i, t_board *board, char neg)
{
  if (str[i] == neg && str[i + 1] == board->ops[OP_OPEN_PARENT_IDX])
  {
    if (i == 0)
      return (1);
    if (i > 0 && is_ope(board->ops, str[i - 1])
	&& str[i - 1] != board->ops[OP_CLOSE_PARENT_IDX])
      return (1);
  }
  return (0);
}

void	*before_manage_ops(char *expr, unsigned int i, t_board *board)
{
  void	*test_malloc;

  if (is_unary_minus(expr, i, board, board->ops[OP_NEG_IDX]))
    test_malloc = manage_ops(-1, board);
  else
    test_malloc = manage_ops(expr[i], board);
  return (test_malloc);
}

void		*to_npi(t_board *board,
			char *ops, char *expr, unsigned int size)
{
  unsigned int	i;
  void		*test_malloc;

  i = 0;
  test_malloc = "1";
  while (expr[i] && i < size)
  {
    if (check_number(board->base, expr, i, board))
      test_malloc = before_save_nb(expr, &i, board);
    else if (expr[i] == ops[OP_OPEN_PARENT_IDX])
      test_malloc = add_begin_ops(&(board->pile_ops),
				  ops[OP_OPEN_PARENT_IDX]);
    else if (is_ope(ops, expr[i]) && expr[i] != ops[OP_OPEN_PARENT_IDX]
	     && expr[i] != ops[OP_CLOSE_PARENT_IDX])
      test_malloc = before_manage_ops(expr, i, board);
    else if (expr[i] == ops[OP_CLOSE_PARENT_IDX])
      test_malloc = manage_close_parent(board);
    if (test_malloc == NULL)
      return (NULL);
    i = i + 1;
  }
  return ("1");
}

char		*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
  t_board	*board;
  void		*test_calc;

  board = (t_board*)my_malloc(sizeof(*board));
  if (board)
  {
    board->pile_ops = NULL;
    board->pile_calc = NULL;
    board->base	= base;
    board->ops	= ops;
    expr = check_sintax(expr, board, ops, size);
    if (expr)
    {
      test_calc = to_npi(board, ops, expr, size);
      if (test_calc == NULL)
      	return ("");
      free(expr);
      test_calc = calculate_pile(board);
      if (test_calc == NULL)
	return ("");
      clean_final(board->pile_calc->nb, base, ops[OP_NEG_IDX]);
      return (board->pile_calc->nb);
    }
  }
  return ("");
}
