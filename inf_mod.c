/*
** inf_mod.c for bistro in /home/chapui_s/travaux/bistro/tmp
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Tue Nov  5 18:39:33 2013 chapui_s
** Last update Sun Nov 10 19:18:16 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

char	*inf_mod(char *n1, char *n2, char *base, char neg)
{
  char	*tmp;
  int	negativ;

  negativ = 0;
  if (n1[0] == neg && n2[0] == neg)
    negativ = 1;
  else if (n1[0] == neg && n2[0] != neg)
    negativ = 1;
  else
    negativ = 0;
  if (n1[0] == neg)
    n1[0] = base[0];
  if (n2[0] == neg)
    n2[0] = base[0];
  clean_nbs(n1, n2, base);
  tmp = inf_div(n1, n2, base, neg);
  tmp = inf_mult(tmp, n2, base, neg);
  tmp = inf_sub(n1, tmp, base, neg);
  if (negativ == 1)
  {
    if (!(tmp[0] == base[0] && tmp[1] == '\0'))
      tmp = add_minus(tmp, neg);
  }
  return (tmp);
}
