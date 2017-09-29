/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pad_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 13:37:24 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 17:21:09 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_paddingtool(int pad, int len)
{
	int		nbr;

	nbr = pad - len;
	while (nbr > 0)
	{
		write(1, " ", 1);
		nbr--;
	}
}

static void		ft_get_totalblock(t_list *print, char *flags)
{
	t_list	*tmp;
	int		totalblock;
	int		display;

	display = 0;
	totalblock = 0;
	tmp = print;
	while (tmp)
	{
		if ((((t_ls*)tmp->content)->name)[0] == '.' && (!(ft_strchr(flags, 'a'))))
			;
		else
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

void		ft_getmax_l(t_list *print, char *flags, t_pad *pad)
{
	t_list	*tmp;

	tmp = print;
	if (!(ft_strchr(flags, 'a')))
		while ((((t_ls*)tmp->content)->name[0] == '.') && tmp)
			tmp = tmp->next;
	while (tmp)
	{
		if (ft_intlen(((t_ls*)tmp->content)->links) > pad->links)
			pad->links = (ft_intlen(((t_ls*)tmp->content)->links));
		if (ft_strlen(((t_ls*)tmp->content)->owner) > (size_t)pad->owner)
			pad->owner = (ft_strlen(((t_ls*)tmp->content)->owner));
		if (ft_strlen(((t_ls*)tmp->content)->group) > (size_t)pad->group)
			pad->group = (ft_strlen(((t_ls*)tmp->content)->group));
		if (ft_intlen(((t_ls*)tmp->content)->size) > pad->size)
			pad->size = (ft_intlen(((t_ls*)tmp->content)->size));
		if ((ft_intlen(((t_ls*)tmp->content)->major)) > pad->major)
		{
			pad->major = (ft_intlen(((t_ls*)tmp->content)->major));
			pad->ismajor = 1;
		}
		tmp = tmp->next;
	}
}

static void	ft_pad_init(t_pad *pad)
{
	pad->iscontent = 0;
	pad->links = 0;
	pad->owner = 0;
	pad->group = 0;
	pad->size = 0;
	pad->major = 0;
	pad->ismajor = 0;
}

t_pad		*ft_pad_l(t_list *print, char *flags, t_pad *pad)
{
	pad = ft_memalloc(sizeof(t_pad));
	ft_pad_init(pad);
	ft_get_totalblock(print, flags);
	ft_getmax_l(print, flags, pad);
	return (pad);
}
