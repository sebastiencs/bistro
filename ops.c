/*
** ops.c for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct 28 23:05:48 2013 chapui_s
** Last update Sun Nov 10 22:54:48 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	prior_ops(char op_pile, char op_cur, char *ops)
{
  if ((op_cur == ops[OP_MULT_IDX] || op_cur == ops[OP_DIV_IDX]
       || op_cur == ops[OP_MOD_IDX]) && (op_pile == ops[OP_PLUS_IDX]
					  || op_pile == ops[OP_SUB_IDX]))
    return (1);
  return (0);
}

int	test_if_zero(char *nb, char *base, char op, t_board *board)
{
  if (*nb == base[0] || *nb == board->ops[OP_NEG_IDX])
  {
    while (*(nb + 1) == base[0])
      nb = nb + 1;
  }
  if (nb[0] == base[0] && nb[1] == '\0')
  {
    if (op == board->ops[OP_MOD_IDX])
      my_putstr("Error: Modulo by zero");
    else
      my_putstr("Error: Divide by zero");
    return (1);
  }
  return (0);
}

char	*do_op(char *nb1, char op, char *nb2, t_board *board)
{
  char	*result;

  result = NULL;
  if (op == board->ops[OP_PLUS_IDX])
    result = inf_add(nb2, nb1, board->base, board->ops[OP_NEG_IDX]);
  else if (op == board->ops[OP_MULT_IDX])
    result = inf_mult(nb1, nb2, board->base, board->ops[OP_NEG_IDX]);
  else if (op == board->ops[OP_SUB_IDX])
    result = inf_sub(nb2, nb1, board->base, board->ops[OP_NEG_IDX]);
  else if (op == board->ops[OP_DIV_IDX])
  {
    if (test_if_zero(nb1, board->base, op, board))
      return (NULL);
    result = inf_div(nb2, nb1, board->base, board->ops[OP_NEG_IDX]);
  }
  else if (op == board->ops[OP_MOD_IDX])
  {
    if (test_if_zero(nb1, board->base, op, board))
      return (NULL);
    result = inf_mod(nb2, nb1, board->base, board->ops[OP_NEG_IDX]);
  }
  else if (op == -1)
    result = inf_mult("-1", nb1, board->base, board->ops[OP_NEG_IDX]);
  return (result);
}

void	*manage_ops(char op, t_board *board)
{
  void	*test_malloc;

  if (board->pile_ops == NULL)
    test_malloc = add_begin_ops(&(board->pile_ops), op);
  else if (board->pile_ops->op == board->ops[OP_OPEN_PARENT_IDX])
    test_malloc = add_begin_ops(&(board->pile_ops), op);
  else if (prior_ops(board->pile_ops->op, op, board->ops) == 1)
    test_malloc = add_begin_ops(&(board->pile_ops), op);
  else
  {
    while (board->pile_ops
	   && board->pile_ops->op == board->ops[OP_OPEN_PARENT_IDX])
      rm_first_ops(&(board->pile_ops));
    if (board->pile_calc->next)
    {
      test_malloc = little_calc(board);
      if (test_malloc == NULL)
      	return (NULL);
    }
    test_malloc = add_begin_ops(&(board->pile_ops), op);
  }
  if (test_malloc == NULL)
    return (NULL);
  return ("1");
}

void	*manage_close_parent(t_board *board)
{
  void	*test_malloc;

  while (board->pile_ops
	 && (board->pile_ops->op != board->ops[OP_OPEN_PARENT_IDX])
	 && (board->pile_calc->next))
  {
    test_malloc = little_calc(board);
    if (test_malloc == NULL)
      return (NULL);
  }
  if (board->pile_ops->op != -1)
    board->pile_ops = rm_first_ops(&(board->pile_ops));
  return ("1");
}
