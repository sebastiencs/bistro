/*
** little_calc.c for bistro in /home/chapui_s/travaux/new_bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Fri Nov  8 15:24:01 2013 chapui_s
** Last update Sun Nov 10 19:18:57 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void	*little_calc(t_board *board)
{
  char	*tmp;
  void	*test_malloc;

  if (board->pile_ops)
    {
      if (board->pile_ops->op != -1)
	tmp = do_op(board->pile_calc->nb, board->pile_ops->op,
		    board->pile_calc->next->nb, board);
      else
	tmp = do_op(board->pile_calc->nb, board->pile_ops->op,
		    "", board);
      if (tmp == NULL)
	return (NULL);
      if (board->pile_ops->op != -1)
	rm_first_calc(&(board->pile_calc));
      rm_first_calc(&(board->pile_calc));
      rm_first_ops(&(board->pile_ops));
      test_malloc = add_begin_calc(&(board->pile_calc), tmp);
      if (test_malloc == NULL)
	return (NULL);
    }
  return ("1");
}

void	*little_rev_calc(t_board *board)
{
  char	*tmp;
  void	*test_malloc;

  if (board->pile_ops)
    {
      if (board->pile_ops->op != -1)
	tmp = do_op(board->pile_calc->next->nb, board->pile_ops->op,
		    board->pile_calc->nb, board);
      else
	tmp = do_op(board->pile_calc->nb, board->pile_ops->op,
		    "", board);
      if (tmp == NULL)
	return (NULL);
      if (board->pile_ops->op != -1)
	rm_first_calc(&(board->pile_calc));
      rm_first_calc(&(board->pile_calc));
      rm_first_ops(&(board->pile_ops));
      test_malloc = add_begin_calc(&(board->pile_calc), tmp);
      if (test_malloc == NULL)
	return (NULL);
    }
  return ("1");
}
