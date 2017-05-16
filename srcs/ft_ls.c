/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:00:32 by apissier          #+#    #+#             */
/*   Updated: 2017/05/15 16:57:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include "../libft/libft.h"

void			ft_get_flag(char **av, t_flags b, int i)
{
  int		y;

  y = 0;
  if (av[i][y] == '-')
    while (av[i][y])
      {
	y++;
	(av[i][y] == 'l' ? (b->l = 1) : (b->l = 0));
	(av[i][y] == 'R' ? (b->R = 1) : (b->R = 0));
	(av[i][y] == 'a' ? (b->a = 1) : (b->a = 0));
	(av[i][y] == 'r' ? (b->r = 1) : (b->r = 0));
	(av[i][y] == 't' ? (b->t = 1) : (b->t = 0));
      }
  if (b->l == 0 && b->R == 0 && b->a == 0 && b->r == 0 && b->t == 0 && av[1][0] == '-')
    ft_putstr("Try 'ls --h' for more information.\n");
}			

int			main(int ac, char **av)
{
  int		i;
  t_flags		b;
  
  i = 1;
  b = (t_flags){0, 0, 0, 0, 0};
  while (av[i])
    {
      ft_get_flag(av, &b, i);
      i++;
    }
  if (ac == 1)
}
