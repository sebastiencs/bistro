/*
** check_sintax_fct.c for check_syntax in /home/denel-_l/rendu/Bistro/2_bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Sun Nov 10 15:58:59 2013 lowik_denel
** Last update Sun Nov 10 19:15:00 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	is_ops_no_parents(char c, char *ops)
{
  int	i;

  i = 2;
  while (ops[i])
  {
    if (ops[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}

int	is_ops_no_parents_no_pm(char c, char *ops)
{
  int	i;

  i = 4;
  while (ops[i])
  {
    if (ops[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}

int		is_spaces_in_ops_base(t_board *board, char *ops)
{
  unsigned int	i;

  i = 0;
  while (ops[i])
  {
    if (ops[i] == ' ')
      return (1);
    i = i + 1;
  }
  i = 0;
  while (board->base[i])
  {
    if (board->base[i] == ' ')
      return (1);
    i = i + 1;
  }
  return (0);
}

char		*rm_spaces(char *str, t_board *board, char *ops)
{
  unsigned int	i;
  unsigned int	j;
  char		*new_expr;

  if (is_spaces_in_ops_base(board, ops) == 1)
    return (str);
  new_expr = (char*)my_malloc(sizeof(char) * (my_strlen(str) + 1));
  if (new_expr == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str[i])
  {
    if (str[i] != ' ' && str[i] != -1)
    {
      new_expr[j] = str[i];
      j = j + 1;
    }
    i = i + 1;
  }
  new_expr[j] = '\0';
  free(str);
  if (j == 0)
    return ("");
  return (new_expr);
}

int		is_last_car_parent(char *str, unsigned int i, t_board *board)
{
  while (i > 1 && str[i] == -1)
    i = i - 1;
  if (str[i] == board->ops[OP_OPEN_PARENT_IDX])
    return (1);
  if (str[i] == board->ops[OP_DIV_IDX])
    return (1);
  if (str[i] == board->ops[OP_MULT_IDX])
    return (1);
  if (str[i] == board->ops[OP_MOD_IDX])
    return (1);
  if (str[i] == board->ops[OP_CLOSE_PARENT_IDX])
    return (0);
  return (0);
}
