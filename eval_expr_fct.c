/*
** eval_expr_fct.c for eval_expr in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 16:18:15 2013 lowik_denel
** Last update Sun Nov 10 19:16:30 2013 lowik_denel
*/

#include <stdlib.h>
#include "bistromathique.h"
#include "header.h"

unsigned int	save_nb(char *expr, t_board *board)
{
  unsigned int	i;
  unsigned int	size;
  char		*new_nb;
  void		*test_malloc;

  i		= 0;
  size		= 0;
  if (expr[0] == board->ops[OP_NEG_IDX])
    size = size + 1;
  while (is_number(board->base, expr[size]))
    size = size + 1;
  new_nb	= (char*)my_malloc(sizeof(*new_nb) * (size + 1));
  if (new_nb == NULL)
    return (0);
  while (i < size && expr[i])
  {
    new_nb[i] = expr[i];
    i = i + 1;
  }
  new_nb[i] = '\0';
  test_malloc = add_begin_calc(&(board->pile_calc), new_nb);
  if (test_malloc == NULL)
    return (0);
  return (size);
}

void		clean_final(char *str, char *base, char neg)
{
  size_t	i;
  int		move;

  i = 0;
  move = 0;
  if (*str == neg)
  {
    move = 1;
    str = str + 1;
  }
  while (str[0] == base[0] && str[1] != '\0')
  {
    i = 0;
    while (str[i])
    {
      str[i] = str[i + 1];
      i = i + 1;
    }
  }
  if (move)
    str = str - 1;
  if (str[0] == neg && str[1] == base[0]
      && str[2] == '\0')
  {
    str[0] = base[0];
    str[1] = '\0';
  }
}

void		*before_save_nb(char *expr, unsigned int *i, t_board *board)
{
  unsigned int	size_nb;

  size_nb = 0;
  size_nb = save_nb(expr + *i, board);
  if (size_nb == 0)
    return (NULL);
  *i = *i + size_nb - 1;
  return ("1");
}
