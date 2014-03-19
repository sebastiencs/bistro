/*
** my_putchar.c for my_putchar in /home/denel-_l/rendu/Piscine-C-lib/my
** 
** Made by lowik_denel
** Login   <denel-_l@epitech.net>
** 
** Started on  Mon Oct 21 10:43:18 2013 lowik_denel
** Last update Sun Nov 10 20:45:36 2013 lowik_denel
*/

#include <stdlib.h>
#include "header.h"
#include "bistromathique.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
