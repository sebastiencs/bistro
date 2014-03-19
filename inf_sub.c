/*
** inf_sub.c for bistro in /home/chapui_s/travaux/inf_sub
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Thu Oct 31 18:09:36 2013 chapui_s
** Last update Sun Nov 10 19:17:35 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"


char		*prepare_inf_sub(char *n1, char *n2, char *base, char neg)
{
  size_t	i;
  char		*tmp;
  int		*tmp_int;
  int		is_change;
  char		*result;

  is_change = 0;
  if (find_order(n1, n2, base, neg) == 2)
  {
    tmp = n1;
    n1 = n2;
    n2 = tmp;
    is_change = 1;
  }
  result = (char*)my_malloc(sizeof(char) * (my_strlen(n1) + 3));
  if (result == NULL)
    return (result);
  result[my_strlen(n1) + 2] = '\0';
  tmp_int = do_inf_sub(n1, n2, base, 0);
  if (tmp_int == NULL)
    return (NULL);
  tmp_to_res(tmp_int, result, base, n1);
  clean_sub(result, is_change, neg, base);
  return (result);
}

char    *prep_two_neg(char *n1, char *n2, char *base, char neg)
{
  char *tmp;

  n1[0] = base[0];
  n2[0] = base[0];
  tmp = n1;
  n1 = n2;
  n2 = tmp;
  return (prepare_inf_sub(n1, n2, base, neg));
}

char		*add_then_neg(char *n1, char *n2, char *base, char neg)
{
  char		*tmp;
  char		*result;
  size_t	size_tmp;
  size_t	i;

  i = 0;
  n1[0] = base[0];
  tmp = inf_add(n1, n2, base, neg);
  size_tmp = my_strlen(tmp);
  result = (char*)my_malloc(sizeof(char) * (size_tmp + 2));
  result[size_tmp + 1] = '\0';
  if (result == NULL)
    return (result);
  result[0] = neg;
  while (tmp[i])
  {
    result[i + 1] = tmp[i];
    i = i + 1;
  }
  result[i + 1] = '\0';
  free(tmp);
  return (result);
}

char	*sub_add(char *n1, char *n2, char *base, char neg)
{
  n2[0] = base[0];
  return (inf_add(n1, n2, base, neg));
}

char	*inf_sub(char *n1, char *n2, char *base, char neg)
{
  if (n1[0] != neg && n2[0] != neg)
    return (prepare_inf_sub(n1, n2, base, neg));
  if (prepare_inf_sub(n1, n2, base, neg) == NULL)
    return (NULL);
  if (n1[0] != neg && n2[0] == neg)
    return (sub_add(n1, n2, base, neg));
  if (n1[0] == neg && n2[0] != neg)
    {
      return (add_then_neg(n1, n2, base, neg));
      if (add_then_neg(n1, n2, base, neg) == NULL)
	return (NULL);
    }
  else if (n1[0] == neg && n2[0] == neg)
    return (prep_two_neg(n1, n2, base, neg));
}
