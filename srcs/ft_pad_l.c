/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 13:37:24 by apissier          #+#    #+#             */
/*   Updated: 2017/09/18 14:22:20 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void        ft_get_totalblock(t_list *print)
{
    t_list  *tmp;
    int     totalblock;
    int     display;

    display = 0;
    totalblock = 0;
    tmp = print;
    while (tmp)
    {
        totalblock += (((t_ls*)tmp->content)->blocks);
        display++;
        tmp = tmp->next;
    }
    if (display > 0)
    {
        ft_putstr("total ");
        ft_putnbr(totalblock);
        ft_putstr("\n");
        display = 0;
    }
}

t_pad      *ft_pad_l(t_list *print, t_pad *pad)
{
    pad = ft_memalloc(sizeof(t_pad));
    pad = &(t_pad){0, 0, 0 ,0 ,0 ,0 ,0};
    ft_get_totalblock(print);

    return (pad);
}