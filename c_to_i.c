/*
** c_to_i.c for n_to_i in /home/denel-_l/rendu/Bistro/bistro
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Thu Nov  7 10:50:40 2013 lowik_denel
** Last update Sun Nov 10 19:16:03 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

int	c_to_i(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != c)
    i = i + 1;
  return (i);
}
