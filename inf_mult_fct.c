/*
** prepare_mult.c for prepare_for_mult in /home/denel-_l/rendu/Bistro/bistro
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Fri Nov  8 10:49:30 2013 lowik_denel
** Last update Sun Nov 10 19:18:35 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void		prepare_tmp(int *tmp, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size)
  {
    tmp[i] = 0;
    i = i + 1;
  }
}

void		prepare_res(char *result, char *base, size_t size)
{
  size_t	i;

  i = 0;
  while (i < size - 1)
  {
    result[i] = base[0];
    i = i + 1;
  }
  result[size - 1] = '\0';
}
