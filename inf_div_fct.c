/*
** inf_div_fct.c for fonctions_div_inf in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 11:47:18 2013 lowik_denel
** Last update Sun Nov 10 19:18:06 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int		cmp_nbs(char *n1, char *n2, char *base)
{
  size_t	i;
  size_t	j;

  i = 0;
  j = 0;
  while (n1[i] == base[0])
    i = i + 1;
  while (n2[j] == base[0])
    j = j + 1;
  if (my_strlen(n1 + i) > my_strlen(n2 + j))
    return (1);
  if (my_strlen(n2 + j) > my_strlen(n1 + i))
    return (2);
  while (n1[i])
  {
    if (get_id(n1[i], base) > get_id(n2[i], base))
      return (1);
    else if (get_id(n1[i], base) < get_id(n2[i], base))
      return (2);
    i = i + 1;
  }
}

void		init_tmps(char *n, char *tmp)
{
  size_t	i;

  i = 0;
  while (n[i])
  {
    tmp[i] = n[i];
    i = i + 1;
  }
  tmp[i] = '\0';
}

void		clean_nbs(char *n1, char *n2, char *base)
{
  size_t	i;

  while (n1[0] == base[0] && n1[1])
  {
    i = 0;
    while (n1[i])
    {
      n1[i] = n1[i + 1];
      i = i + 1;
    }
    n1[i] = '\0';
  }
  while (n2[0] == base[0] && n2[1])
  {
    i = 0;
    while (n2[i])
    {
      n2[i] = n2[i + 1];
      i = i + 1;
    }
    n2[i] = '\0';
  }
}

char	*ret_simple(char *base, int nb, int negativ, char neg)
{
  char	*res;

  res = (char*)my_malloc(sizeof(char) * 3);
  if (res == NULL)
    return (NULL);
  res[0] = base[0];
  res[1] = '\0';
  if (nb == 1)
    res[0] = base[1];
  if (nb == 1 && negativ == 1)
  {
    res[0] = neg;
    res[1] = base[1];
    res[2] = '\0';
  }
  return (res);
}

void	free_tmps(t_vars_div *vars)
{
  free(vars->tmp_n1);
  free(vars->tmp_n2);
  free(vars->save_tmp);
}
