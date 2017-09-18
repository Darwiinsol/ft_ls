/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 11:46:29 by apissier          #+#    #+#             */
/*   Updated: 2017/09/18 15:39:02 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

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

void		ft_print_foldername(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void		ft_print(t_list *print, char *flags)
{
	t_list	*tmp;
	t_pad	*pad;

	tmp = print;
	pad = NULL;

	if (ft_strchr(flags, 'l') && tmp)
		ft_pad_l(print, pad);
	while (tmp)
	{
		if (!(ft_strchr(flags, 'a')))
			while (((t_ls*)tmp->content)->name[0] == '.')
				tmp = tmp->next;
		ft_putstr(((t_ls*)tmp->content)->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	
}