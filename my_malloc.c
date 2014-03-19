/*
** xmalloc.c for xmalloc in /home/denel-_l/rendu/Bistro/bistro
**
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
**
** Started on  Fri Nov  8 13:52:30 2013 lowik_denel
** Last update Sun Nov 10 19:19:50 2013 lowik_denel
*/

#include <stdlib.h>
#include "bistromathique.h"

void	*my_malloc(size_t size)
{
  void	*tmp;

  tmp = NULL;
  tmp = malloc(size);
  if (tmp == NULL)
    {
      my_putstr("could not alloc");
      return (NULL);
    }
  return (tmp);
}
