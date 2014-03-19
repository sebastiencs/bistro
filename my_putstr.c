/*
** my_putstr.c for my_put_str in /home/denel-_l/rendu/Piscine-C-Jour_04
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Thu Oct  3 10:28:00 2013 lowik_denel
** Last update Sun Nov 10 19:20:10 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void	my_putstr(char *str)
{
  size_t	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
