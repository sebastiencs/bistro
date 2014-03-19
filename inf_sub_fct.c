/*
** inf_sub_fct.c for fonctions_sub_inf in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 11:34:00 2013 lowik_denel
** Last update Sun Nov 10 19:17:43 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

size_t		size_nb(char *nb, char *base)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (nb[j] == base[0])
    j = j + 1;
  while (nb[i + j])
    i = i + 1;
  return (i);
}

int		find_order(char *n1, char *n2, char *base, char neg)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (n1[i] == base[0] || n1[i] == base[0])
    i = i + 1;
  while (n2[j] == base[0] || n2[j] == base[0])
    j = j + 1;
  if (size_nb(n1 + i, base) > size_nb(n2 + j, base))
    return (1);
  else if (size_nb(n1 + i, base) < size_nb(n2 + j, base))
    return (2);
  while (n1[i])
  {
    if (get_id(n1[i], base) > get_id(n2[j], base))
      return (1);
    else if (get_id(n1[i], base) < get_id(n2[j], base))
      return (2);
    i = i + 1;
    j = j + 1;
  }
  return (0);
}

int		*do_inf_sub(char *n1, char *n2, char *base, int ret)
{
  int	len_n1;
  int	len_n2;
  int	*tmp;

  len_n1 = my_strlen(n1) - 1;
  len_n2 = my_strlen(n2) - 1;
  tmp = (int*)my_malloc(sizeof(*tmp) * len_n1 + 3);
  if (tmp == NULL)
    return (tmp);
  while (len_n1 >= 0)
  {
    if (len_n2 >= 0)
      tmp[len_n1] = get_id(n1[len_n1], base) - get_id(n2[len_n2], base) - ret;
    else
      tmp[len_n1] = get_id(n1[len_n1], base) - get_id(base[0], base) - ret;
    if (tmp[len_n1] < 0)
      ret = 1;
    if (tmp[len_n1] < 0)
      tmp[len_n1] = tmp[len_n1] + my_strlen(base);
    else
      ret = 0;
    len_n1 = len_n1 - 1;
    len_n2 = len_n2 - 1;
  }
  return (tmp);
}

void		clean_sub(char *result, int is_change, char neg, char *base)
{
  size_t	i;

  i = 0;
  if (is_change == 1)
    result[0] = neg;
  while ((result[0] == base[0] || (result[0] == neg && result[1] == base[0]))
	 && result[1] != '\0')
  {
    i = 0;
    if (result[0] == neg)
      i = 1;
    while (result[i])
    {
      result[i] = result[i + 1];
      i = i + 1;
    }
    result[i] = '\0';
  }
  i = 0;
  while (result[i])
    i = i + 1;
  if (i > 1)
    result[i] = '\0';
  else
    result[2] = '\0';
}

void		tmp_to_res(int *tmp_int, char *result, char *base, char *n1)
{
  size_t	size;
  size_t	i;

  i = 0;
  size = my_strlen(n1);
  while (i < size + 3)
  {
    result[i] = '\0';
    i = i + 1;
  }
  while (size > 0)
  {
    result[size] = base[tmp_int[size - 1]];
    size = size - 1;
  }
  result[0] = base[tmp_int[-1]];
}
