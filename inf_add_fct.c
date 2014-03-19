/*
** inf_mult_fct.c for fonctions_inf_mult in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 11:21:26 2013 lowik_denel
** Last update Sun Nov 10 19:17:24 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void	clean_result(char *str, char *base, char neg)
{
  int	i;

  while (str[0] == base[0])
  {
    i = 0;
    while (str[i])
    {
      str[i] = str[i + 1];
      i = i + 1;
    }
    str[i] = '\0';
  }
  i = 0;
  while (is_it_nb(str[i], base) || str[i] == neg)
    i = i + 1;
  if (i == 0)
  {
    str[0] = base[0];
    str[1] = '\0';
  }
  else
    str[i] = '\0';
}

int	size_number(char *str)
{
  size_t	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
