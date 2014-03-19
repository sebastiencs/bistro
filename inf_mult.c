/*
** inf_mult.c for bistro in /home/chapui_s/travaux/add_inf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Wed Oct 30 20:55:11 2013 chapui_s
** Last update Sun Nov 10 19:32:45 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

t_mult		*init_vars_mult(char *n1, char *n2, char neg, char *base)
{
  t_mult	*vars;

  vars = (t_mult*)my_malloc(sizeof(*vars));
  if (vars == NULL)
    return (NULL);
  vars->size_n1 = my_strlen(n1);
  vars->size_n2 = my_strlen(n2);
  if (n1[0] == neg)
  {
    vars->size_n1 = vars->size_n1 - 1;
    vars->n1 = n1 + 1;
  }
  else
    vars->n1 = n1;
  if (n2[0] == neg)
  {
    vars->size_n2 = vars->size_n2 - 1;
    vars->n2 = n2 + 1;
  }
  else
    vars->n2 = n2;
  vars->base = base;
  vars->neg = neg;
  return (vars);
}

int		*do_inf_mult_int(t_mult *v, int *tmp, char *base)
{
  size_t	c_1;
  size_t	c_2;
  char		*n1;
  char		*n2;
  int		size_base;

  n1 = v->n1;
  n2 = v->n2;
  c_1 = v->size_n1;
  size_base = my_strlen(base);
  while (c_1 > 0)
  {
    c_2 = v->size_n2;
    while (c_2 > 0)
    {
      tmp[c_1 + c_2 - 1] = tmp[c_1 + c_2 - 1]
	+ (c_to_i(n1[c_1 - 1], base) * c_to_i(n2[c_2 - 1], base));
      tmp[c_1 + c_2 - 2] = tmp[c_1 + c_2 - 2]
	+ tmp[c_1 + c_2 - 1] / size_base;
      tmp[c_1 + c_2 - 1] = tmp[c_1 + c_2 - 1] % size_base;
      c_2 = c_2 - 1;
    }
    c_1 = c_1 - 1;
  }
  return (tmp);
}

char		*mult_to_char(t_mult *v, int *tmp, char *result, char *base)
{
  size_t	c_1;
  size_t	c_2;
  size_t	size_n1;
  size_t	size_n2;

  c_1 = 0;
  c_2 = 0;
  size_n1 = v->size_n1;
  size_n2 = v->size_n2;
  while (c_1 < size_n1 + size_n2)
  {
    result[c_2 + 1] = base[tmp[c_1]];
    c_2 = c_2 + 1;
    c_1 = c_1 + 1;
  }
  result[c_1 + 1] = '\0';
  return (result);
}

void		clean_result_mult(char *result, char *n1, char *n2, t_mult *v)
{
  size_t	i;

  i = 0;
  if ((n1[0] == v->neg && n2[0] != v->neg)
      || (n1[0] != v->neg && n2[0] == v->neg))
  {
    while (result[i] == v->base[0])
      i = i + 1;
    result[i - 1] = v->neg;
    if (result[i] == '\0' && result[i - 1] == v->neg)
      result[i - 1] = v->base[0];
  }
  while (result[0] == v->base[0] && result[1] != '\0')
  {
    i = 0;
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
  result[i] = '\0';
}

char		*inf_mult(char *n1, char *n2, char *base, char neg)
{
  t_mult	*vars;
  char		*result;
  int		*tmp;
  char		*swap;

  vars = init_vars_mult(n1, n2, neg, base);
  if (vars == NULL)
    return (NULL);
  result = (char*)my_malloc(sizeof(char) * (vars->size_n1
					    + vars->size_n2) + 2);
  tmp = (int*)my_malloc(sizeof(int) * (vars->size_n1 + vars->size_n2));
  if (result == NULL || tmp == NULL)
    return (NULL);
  prepare_tmp(tmp, vars->size_n1 + vars->size_n2);
  tmp = do_inf_mult_int(vars, tmp, base);
  prepare_res(result, base, vars->size_n1 + vars->size_n2 + 2);
  result = mult_to_char(vars, tmp, result, base);
  clean_result_mult(result, n1, n2, vars);
  return (result);
}
