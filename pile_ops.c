/*
** pile_ops.c for bistro in /home/chapui_s/travaux/bistro
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Mon Oct 28 22:32:17 2013 chapui_s
** Last update Sun Nov 10 19:20:59 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

t_pile_ops	*create_pile_ops(char op)
{
  t_pile_ops	*new;

  new = NULL;
  new = (t_pile_ops*)my_malloc(sizeof(*new));
  if (new)
  {
    new->op = op;
    new->next = NULL;
  }
  return (new);
}

void		*add_begin_ops(t_pile_ops **pile_ops, char op)
{
  t_pile_ops	*new;

  if (*pile_ops)
  {
    new = create_pile_ops(op);
    if (new)
    {
      new->next = *pile_ops;
      *pile_ops = new;
    }
    else
      return (NULL);
  }
  else
  {
    *pile_ops = create_pile_ops(op);
    if (*pile_ops == NULL)
      return (NULL);
  }
  return ("1");
}

t_pile_ops	*rm_first_ops(t_pile_ops **pile_ops)
{
  t_pile_ops	*tmp;

  tmp = NULL;
  if (*pile_ops)
  {
    tmp = *pile_ops;
    *pile_ops = (*pile_ops)->next;
    free(tmp);
    return (*pile_ops);
  }
  else
    return (NULL);
}

void	reverse_ops(t_pile_ops **begin_list)
{
  t_pile_ops	*list;
  t_pile_ops	*tmp;
  t_pile_ops	*tmp2;

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
