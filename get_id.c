/*
** get_id.c for get_id in /home/denel-_l/rendu/Bistro
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Wed Nov  6 09:29:49 2013 lowik_denel
** Last update Sun Nov 10 19:16:38 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	get_id(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != c)
    {
      i = i + 1;
    }
  return (i);
}
