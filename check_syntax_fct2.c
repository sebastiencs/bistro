/*
** check_sintax_fct2.c for check in /home/denel-_l/rendu/Bistro/2_bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Sun Nov 10 16:02:33 2013 lowik_denel
** Last update Sun Nov 10 19:28:24 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int		check_first_plus(char *str, char plus)
{
  unsigned int	i;

  i = 0;
  while (str[i] == -1)
    i = i + 1;
  if (str[i] == plus)
    str[i] = -1;
  return (0);
}

int		rm_plus_minus(char *str, char plus, char minus, t_board *board)
{
  unsigned int	i;

  i = 0;
  while (str[i])
  {
    if ((str[i] == minus && str[i + 1] == minus)
	|| (str[i] == plus && str[i + 1] == plus))
    {
      str[i] = -1;
      if (str[i + 1] == minus
	  && is_last_car_parent(str, i, board) == 0)
	str[i + 1] = plus;
      else
      	str[i + 1] = -1;
    }
    if ((str[i] == plus && str[i + 1] == minus)
	|| (str[i] == minus && str[i + 1] == plus))
    {
      str[i] = -1;
      str[i + 1] = minus;
    }
    i = i + 1;
  }
  return (check_first_plus(str, plus));
}

int		check_parent(char *str, char open_p, char close_p)
{
  unsigned int	i;
  unsigned int	nb_open;
  unsigned int	nb_close;

  i = 0;
  nb_open = 0;
  nb_close = 0;
  while (str[i])
  {
    if (str[i] == open_p)
      nb_open = nb_open + 1;
    else if (str[i] == close_p)
      nb_close = nb_close + 1;
    if (nb_close > nb_open)
      return (1);
    if (str[i] == open_p && str[i + 1] == close_p)
      return (1);
    if (str[i] == close_p && str[i + 1] == open_p)
      return (1);
    i = i + 1;
  }
  if (nb_open != nb_close)
    return (1);
  return (0);
}

int	check_left_right_op(char *str, unsigned int i, char *ops, char *base)
{
  if (str[i + 1] == '\0')
    return (1);
  if (str[i] != ops[OP_NEG_IDX])
  {
    if (i > 0 && str[i - 1] == ops[OP_OPEN_PARENT_IDX])
      return (1);
    if (i == 0)
      return (1);
  }
  return (0);
}

int	is_nbs_after_last_op(unsigned int i, char *str, char *base, char *ops)
{
  i = i - 1;
  while (i > 0 && is_number(base, str[i]) == 0)
  {
    if (is_ops_no_parents(str[i], ops))
      return (1);
    i = i - 1;
  }
  return (0);
}
