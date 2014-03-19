/*
** my_strlen.c for my_strlen in /home/denel-_l/rendu/Piscine-C-Jour_04
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Thu Oct  3 13:58:35 2013 lowik_denel
** Last update Sun Nov 10 19:20:24 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

unsigned int	my_strlen(char *str)
{
  unsigned int	c;
  unsigned int	i;

  i = 0;
  c = *str;
  while (c != 0)
  {
    str = str + 1;
    i = i + 1;
    c = *str;
  }
  return (i);
}

