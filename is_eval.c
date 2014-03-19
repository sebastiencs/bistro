/*
** is_eval.c for is_eval in /home/denel-_l/rendu/Bistro/bistro
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Fri Nov  8 09:24:50 2013 lowik_denel
** Last update Sun Nov 10 19:18:46 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	is_ope(char *ops, char c)
{
  int	i;

  i	= 0;
  while (ops[i])
  {
    if (ops[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}

int	is_number(char *base, char c)
{
  int	i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}

int	is_it_nb(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i])
  {
    if (base[i] == c)
      return (1);
    i = i + 1;
  }
  return (0);
}
