/*
** check_base_syntax.c for check_base in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 17:25:48 2013 lowik_denel
** Last update Sun Nov 10 19:57:23 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int		check_str(char c, char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
	return (0);
      i = i + 1;
    }
  return (1);
}

int		check_double(char *base, char *opr)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  j = 0;
  while (base[i])
  {
    j = 0;
    while (opr[j])
    {
      if (base[i] == opr[j])
	return (1);
      j = j + 1;
    }
    i = i + 1;
  }
  return (0);
}

int		is_double_in_str(char *str)
{
  unsigned int	i;
  unsigned int	j;

  i = 0;
  while (str[i])
  {
    j = i + 1;
    while (str[j])
    {
      if (str[i] == str[j])
	return (1);
      j = j + 1;
    }
    i = i + 1;
  }
  return (0);
}

char		*str_base_opr(char *opr, char *base)
{
  char		*str;
  unsigned int	i;
  int		j;

  i = 0;
  j = 0;
  str = (char*)my_malloc(sizeof(TO_LEN(opr) + BASE_LEN(base)) + 1);
  if (str == NULL)
    return (NULL);
  str[TO_LEN(opr) + BASE_LEN(base)] = '\0';
  while (i != TO_LEN(opr))
    {
      str[i] = opr[i];
      i = i + 1;
    }
  while (j != BASE_LEN(base))
    {
      str[i] = base[j];
      i = i + 1;
      j = j + 1;
    }
  return (str);
}

char		check_base_opr(char *expr,
			       t_board *board, char *opr, unsigned int size)
{
  unsigned int	i;
  char		*base;
  char		*str;

  i = 0;
  base = board->base;
  str = str_base_opr(opr, base);
  if (is_double_in_str(base) || is_double_in_str(opr))
    return (1);
  if (check_double(base, opr) == 0)
  {
    while (expr[i])
    {
      if (check_str(expr[i], str) == 0)
	i = i + 1;
      else
	return (1);
    }
    return (0);
  }
  else
    return (1);
}
