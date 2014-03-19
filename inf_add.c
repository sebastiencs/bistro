/*
** main.c for bistro in /home/chapui_s/travaux/add_inf
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Oct 29 18:41:26 2013 chapui_s
** Last update Sun Nov 10 19:17:15 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void	init_vars(t_vars_add *vars, char *nb1, char *nb2, char *base)
{
  int	i;

  i = 0;
  vars->result = NULL;
  vars->size_nb1 = size_number(nb1) - 1;
  vars->size_nb2 = size_number(nb2) - 1;
  vars->size_res = TO_DIF(vars->size_nb1 + 1, vars->size_nb2 + 1) + 1;
  vars->nb1 = nb1;
  vars->nb2 = nb2;
  vars->base = base;
  vars->result = (char*)my_malloc(sizeof(char) * (vars->size_res + 2));
  if (vars->result)
  {
    vars->result[vars->size_res + 1] = '\0';
    while (i < vars->size_res)
    {
      vars->result[i] = base[0];
      i = i + 1;
    }
    vars->result[i] = '\0';
  }
}

int	is_nb_neg(char *nb1, char *nb2, char neg)
{
  if (nb1[0] == neg && nb2[0] == neg)
    return (0);
  if (nb1[0] != neg && nb2[0] != neg)
    return (0);
  return (1);
}

void		do_add_pos(t_vars_add *v, char neg, int size_r, int is_neg)
{
  int		ret;
  int		size_base;

  ret = 0;
  size_base = size_number(v->base);
  while (v->size_nb1 >= 0 || v->size_nb2 >= 0 || ret != 0)
  {
    v->result[size_r] = ret;
    if (v->size_nb1 >= 0)
      v->result[size_r] = v->result[size_r]
	+ get_id(v->nb1[v->size_nb1], v->base);
    if (v->size_nb2 >= 0)
      v->result[size_r] = v->result[size_r]
	+ get_id(v->nb2[v->size_nb2], v->base);
    ret = v->result[size_r] / size_base;
    v->result[size_r] = v->result[size_r] % size_base;
    v->result[size_r] = v->base[v->result[size_r]];
    v->size_nb1 = v->size_nb1 - 1;
    v->size_nb2 = v->size_nb2 - 1;
    size_r = size_r - 1;
  }
  while (is_neg && (v->result[size_r + 1] == v->base[0]))
    size_r = size_r + 1;
  if (is_neg)
    v->result[size_r] = neg;
}

char	*do_add_neg(t_vars_add *v, int neg)
{
  if (v->nb1[0] == neg)
  {
    v->nb1[0] = v->base[0];
    return (inf_sub(v->nb2, v->nb1, v->base, neg));
  }
  v->nb2[0] = v->base[0];
  return (inf_sub(v->nb1, v->nb2, v->base, neg));
}

char		*inf_add(char *nb1, char *nb2, char *base, char neg)
{
  t_vars_add	vars;
  int		is_neg;

  vars.neg = neg;
  init_vars(&vars, nb1, nb2, base);
  if (vars.result == NULL)
    return (NULL);
  if (is_nb_neg(nb1, nb2, neg))
    vars.result = do_add_neg(&vars, neg);
  else
  {
    is_neg = 0;
    if (nb1[0] == neg && nb2[0] == neg)
    {
      is_neg = 1;
      nb1[0] = base[0];
      nb2[0] = base[0];
    }
    do_add_pos(&vars, neg, vars.size_res, is_neg);
  }
  clean_result(vars.result, base, neg);
  return (vars.result);
}
