/*
** utils.c for bistro in /home/chapui_s/travaux/new_bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Nov  6 20:45:39 2013 chapui_s
** Last update Sun Nov 10 19:19:38 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

unsigned int		my_atoi(char *str)
{
  unsigned int	i;
  unsigned int	number;

  i = 0;
  number = 0;
  while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
	 || (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
    i = i + 1;
  if (str[i] == '+')
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9')
  {
    number = number * 10;
    number = number + ((size_t)str[i] - '0');
    i = i + 1;
  }
  return (number);
}
