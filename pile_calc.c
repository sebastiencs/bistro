/*
** pile_calc.c for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct 28 22:03:59 2013 chapui_s
** Last update Sun Nov 10 19:20:52 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

t_pile_calc	*create_pile_calc(char *nb)
{
  t_pile_calc	*new;

  new = NULL;
  new = (t_pile_calc*)my_malloc(sizeof(t_pile_calc));
  if (new)
  {
    new->nb = nb;
    new->next = NULL;
  }
  return (new);
}

void		*add_begin_calc(t_pile_calc **pile_calc, char *nb)
{
  t_pile_calc	*new;

  if (*pile_calc)
  {
    new = create_pile_calc(nb);
    if (new)
    {
      new->next = *pile_calc;
      *pile_calc = new;
    }
    else
      return (NULL);
  }
  else
  {
    *pile_calc = create_pile_calc(nb);
    if (*pile_calc == NULL)
      return (NULL);
  }
  return ("1");
}

t_pile_calc	*rm_first_calc(t_pile_calc **pile_calc)
{
  t_pile_calc	*tmp;

  tmp = NULL;
  if (*pile_calc)
  {
    tmp = *pile_calc;
    *pile_calc = (*pile_calc)->next;
    free(tmp->nb);
    return (*pile_calc);
  }
  else
    return (NULL);
}

void		reverse_calc(t_pile_calc **begin_list)
{
  t_pile_calc	*list;
  t_pile_calc	*tmp;
  t_pile_calc	*tmp2;

  tmp = NULL;
  list = *begin_list;
  if (!list || !(list->next))
    return;
  tmp = list->next;
  tmp2 = tmp->next;
  list->next = NULL;
  tmp->next = list;
  while (tmp2)
  {
    list = tmp;
    tmp = tmp2;
    tmp2 = tmp2->next;
    tmp->next = list;
  }
  *begin_list = tmp;
}
