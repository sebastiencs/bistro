/*
** check_sintax.c for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Nov  6 11:11:59 2013 chapui_s
** Last update Sun Nov 10 20:11:36 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int		check_ops(char *str, char *base, char *ops)
{
  unsigned int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i])
  {
    if (is_ops_no_parents(str[i], ops)
	&& check_left_right_op(str, i, ops, base) == 1)
      return (1);
    if (str[i + 1]
	&& is_ops_no_parents(str[i], ops) && is_ops_no_parents(str[i + 1], ops)
	&& str[i + 1] != ops[OP_NEG_IDX])
      return (1);
    if (str[i + 1] && is_ops_no_parents(str[i], ops)
	&& str[i + 1] == ops[OP_CLOSE_PARENT_IDX])
      return (1);
    i = i + 1;
  }
  if (is_nbs_after_last_op(i, str, base, ops))
    return (1);
  return (0);
}

int		check_near_parent(char *str, char *ops, t_board *board)
{
  unsigned int	i;
  char		open_p;
  char		close_p;

  i = 0;
  open_p = ops[OP_OPEN_PARENT_IDX];
  close_p = ops[OP_CLOSE_PARENT_IDX];
  while (str[i])
  {
    if (i > 0 && str[i] == open_p && is_number(board->base, str[i - 1]))
      return (1);
    if (str[i] == close_p && is_number(board->base, str[i + 1]))
      return (1);
    i = i + 1;
  }
  return (0);
}

int		is_space_between_nb(char *str, t_board *board, char *ops)
{
  unsigned int	i;
  int		is_last_nb;

  i = 0;
  if (is_spaces_in_ops_base(board, ops) == 1)
    return (0);
  while (str[i])
  {
    if (is_number(board->base, str[i]) == 1)
      is_last_nb = 1;
    else if (is_ope(ops, str[i]) == 1)
      is_last_nb = 0;
    if (str[i] == ' ' && is_number(board->base, str[i + 1])
	&& is_last_nb == 1)
      return (1);
    i = i + 1;
  }
  return (0);
}

int		is_backslash_n(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\n')
	return (1);
      i = i + 1;
    }
  return (0);
}

char	*check_sintax(char *str, t_board *board, char *ops, unsigned int size)
{
  int	err;

  err = 0;
  if (my_strlen(str) != size || is_backslash_n(str))
    err = 1;
  err = err + is_space_between_nb(str, board, ops);
  str = rm_spaces(str, board, ops);
  if (str != NULL && str[0] != '\0')
  {
    err = err + rm_plus_minus(str, ops[OP_PLUS_IDX], ops[OP_NEG_IDX], board);
    str = rm_spaces(str, board, ops);
    err = err
      + check_parent(str, ops[OP_OPEN_PARENT_IDX], ops[OP_CLOSE_PARENT_IDX]);
    err = err + check_near_parent(str, ops, board);
    err = err + check_ops(str, board->base, ops);
    err = err + check_base_opr(str, board, ops, size);
  }
  if (err > 0 || str[0] == '\0')
  {
    if (str != NULL)
      my_putstr(SYNTAXE_ERROR_MSG);
    return (NULL);
  }
  return (str);
}
