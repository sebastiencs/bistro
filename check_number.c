/*
** check_number.c for check_number in /home/denel-_l/rendu/Bistro/bistro
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Fri Nov  8 08:53:20 2013 lowik_denel
** Last update Sun Nov 10 19:13:41 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	check_number(char *base, char *str, size_t i, t_board *board)
{
  if (is_number(base, str[i]))
    return (1);
  if (str[i] == board->ops[OP_NEG_IDX] && is_number(base, str[i + 1]))
  {
    if (i > 0 && is_ope(board->ops, str[i - 1])
	&& str[i - 1] != board->ops[OP_CLOSE_PARENT_IDX])
      return (1);
    if (i == 0)
      return (1);
  }
  return (0);
}
