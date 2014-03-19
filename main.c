/*
** main.c for bistromathique
**
** Made by Charlie Root
** Login   <rn@epita.fr>
**
** Started on  Tue Oct 23 11:45:05 2001 Charlie Root
** Last update Wed Mar 19 11:32:21 2014 chapui_s
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "bistromathique.h"

void		*my_malloc(size_t size);
void		my_putstr(char *str);
unsigned int	my_strlen(char *str);
unsigned int	my_atoi(char *str);
static int	check_base(char *base);
static int	check_ops(char *ops);
static char	*get_expr(unsigned size);

int		main(int ac, char **av)
{
  char		*expr;
  unsigned int	size;

  if (ac != 4)
  {
    my_putstr("Usage : ");
    my_putstr(av[0]);
    my_putstr(" base ops\"()+-*/%\" exp_len\n");
    return (0);
  }
  if (check_base(av[1]) == 1)
    return (0);
  if (check_ops(av[2]) == 1)
    return (0);
  size = my_atoi(av[3]);
  expr = get_expr(size);
  if (expr == NULL)
    return (0);
  my_putstr(eval_expr(av[1], av[2], expr, size));
  my_putstr("\n");
  return (0);
}

static int	check_base(char *b)
{
  if (my_strlen(b) < 2)
  {
    my_putstr("Bad base");
    return (1);
  }
  return (0);
}

static char	*get_expr(unsigned int size)
{
  char	*expr;

  if (size <= 0)
  {
    my_putstr("Bad expr len");
    return (NULL);
  }
  expr = my_malloc(size + 1);
  if (expr == NULL)
  {
    my_putstr("could not alloc");
    return (NULL);
  }
  if (read(0, expr, size) != size)
  {
    my_putstr("could not read");
    return (NULL);
  }
  expr[size] = 0;
  return (expr);
}

static int	check_ops(char *ops)
{
  if (my_strlen(ops) != 7)
  {
    my_putstr("Bad ops");
    return (1);
  }
  return (0);
}
