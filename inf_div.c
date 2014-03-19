/*
** inf_div.c for bistro in /home/chapui_s/travaux/bistro/tmp
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Nov  4 19:59:05 2013 chapui_s
** Last update Sun Nov 10 21:01:10 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

char	*init_vars_div(char *n1, char *n2, char *base, t_vars_div *v)
{
  v->tmp_n1 = my_malloc(sizeof(char) * (my_strlen(n1) + 1));
  v->tmp_n2 = my_malloc(sizeof(char) * (my_strlen(n1) + 1));
  v->save_tmp = my_malloc(sizeof(char) * (my_strlen(n1) + 1));
  v->save_final = my_malloc(sizeof(char) * (my_strlen(n1) + 1));
  if (v->tmp_n1 == NULL || v->tmp_n2 == NULL || v->save_tmp == NULL
      || v->save_final == NULL)
    return (NULL);
  init_tmps(n1, v->tmp_n1);
  init_tmps(n2, v->tmp_n2);
  v->save_tmp[0] = base[1];
  v->save_tmp[1] = '\0';
  v->save_final[0] = base[0];
  v->save_final[1] = '\0';
  return ("1");
}

char		*size_base(char *base, int size_base)
{
  size_t	size;
  char		str_tmp[1000];
  char		*str_base;
  int		i;

  i = 0;
  size = size_base;
  while (size)
  {
    str_tmp[i] = size % size_base;
    size = size / size_base;
    i = i + 1;
  }
  if ((str_base = (char*)my_malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  size = 0;
  i = i - 1;
  while (i >= 0)
  {
    str_base[size] = base[str_tmp[i]];
    i = i - 1;
    size = size + 1;
  }
  str_base[size] = '\0';
  return (str_base);
}

char		*do_inf_div(char *n1, char *n2, char *base, char neg)
{
  size_t	i;
  t_vars_div	v;
  char		*s_base;

  i = 0;
  if (init_vars_div(n1, n2, base, &v) == NULL)
    return (NULL);
  if ((s_base = size_base(base, my_strlen(base))) == NULL)
    return (NULL);
  while (v.tmp_n1[0] != neg)
  {
    init_tmps(n2, v.tmp_n2);
    v.save_tmp[0] = base[1];
    v.save_tmp[1] = '\0';
    while (cmp_nbs(v.tmp_n1, inf_mult(v.tmp_n2, s_base, base, neg), base) == 1)
    {
      v.save_tmp = inf_mult(v.save_tmp, s_base, base, neg);
      v.tmp_n2 = inf_mult(v.tmp_n2, s_base, base, neg);
    }
    v.tmp_n1 = inf_sub(v.tmp_n1, v.tmp_n2, base, neg);
    if (v.tmp_n1[0] != neg)
      v.save_final = inf_add(v.save_final, v.save_tmp, base, neg);
  }
  free_tmps(&v);
  return (v.save_final);
}

char		*add_minus(char *result, char neg)
{
  size_t	size;
  size_t	i;
  char		*new_result;

  i = 0;
  size = 0;
  new_result = NULL;
  while (result[size])
    size = size + 1;
  new_result = (char*)my_malloc(sizeof(char) * (size + 2));
  if (new_result == NULL)
    return (NULL);
  new_result[size + 1] = '\0';
  new_result[0] = neg;
  while (result[i])
  {
    new_result[i + 1] = result[i];
    i = i + 1;
  }
  new_result[i + 1] = '\0';
  free(result);
  return (new_result);
}

char	*inf_div(char *n1, char *n2, char *base, char neg)
{
  char	*result;
  int	negativ;

  negativ = 0;
  if (n1[0] == neg && n2[0] == neg)
  {
    n1[0] = base[0];
    n2[0] = base[0];
  }
  if (n1[0] == neg || n2[0] == neg)
    negativ = 1;
  if (n2[0] == neg)
    n2[0] = base[0];
  if (n1[0] == neg)
    n1[0] = base[0];
  clean_nbs(n1, n2, base);
  if (cmp_nbs(n1, n2, base) == 0)
    return (ret_simple(base, 1, negativ, neg));
  if (cmp_nbs(n1, n2, base) == 2)
    return (ret_simple(base, 0, negativ, neg));
  result = do_inf_div(n1, n2, base, neg);
  if (negativ == 1 && result != NULL)
    result = add_minus(result, neg);
  return (result);
}
