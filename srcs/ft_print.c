/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:46:29 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 17:25:46 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_print_l(t_list *tmp, char *flags, t_pad *pad)
{
	ft_printf("%s  ", (((t_ls*)tmp->content)->mode));
	ft_paddingtool(pad->links, (ft_intlen((((t_ls*)tmp->content)->links))));
	ft_printf("%d ", (((t_ls*)tmp->content)->links));
	ft_printf("%s  ", (((t_ls*)tmp->content)->owner));
	ft_paddingtool((pad->owner), (ft_strlen(((t_ls*)tmp->content)->owner)));
	ft_printf("%s", (((t_ls*)tmp->content)->group));
	ft_paddingtool((pad->group), (ft_strlen(((t_ls*)tmp->content)->group + 2)));
	ft_print_majorminor(tmp, pad);
	ft_putstr(" ");
	ft_print_goodtime(tmp, flags);
	ft_putstr(" ");
	ft_print_name(tmp);
	if ((((t_ls*)tmp->content)->readlink))
	{
		ft_putstr(" -> ");
		ft_putstr((((t_ls*)tmp->content)->readlink));
	}
}

void		ft_print_list(t_list *list)
{
	t_list	*tmp;
	int		check;

	check = 0;
	tmp = list;
	while (tmp)
	{
		ft_putendl(tmp->content);
		tmp = tmp->next;
		check++;
	}
	if (check > 0)
		ft_putchar('\n');
}

void		ft_print_arg_error(t_list *errorarg)
{
	t_list *tmp;

	tmp = errorarg;
	while (tmp)
	{
		ft_putstr("ft_ls: ");
		ft_putstr((((t_error*)tmp->content)->name));
		ft_putstr(": ");
		ft_putstr(strerror(((t_error*)tmp->content)->errnbr));
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

void		ft_print(t_list *print, char *flags)
{
	t_list	*tmp;
	t_pad	*pad;

	tmp = print;
	pad = NULL;
	if (ft_strchr(flags, 'l') && tmp)
		pad = ft_pad_l(print, flags, pad);
	while (tmp)
	{
		if ((!(ft_strchr(flags, 'a'))) &&
				(((t_ls*)tmp->content)->name[0] == '.'))
			;
		else
		{
			if (ft_strchr(flags, 'l') && tmp)
				ft_print_l(tmp, flags, pad);
			else
				ft_print_noarg(tmp);
			ft_putstr("\n");
		}
		tmp = tmp->next;
	}
}
