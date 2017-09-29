/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:19:14 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 18:16:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list			*ft_check_sort(t_list *liste, char *flags)
{
	if (ft_strchr(flags, 'a') && ft_strchr(flags, 'r') &&
			!(ft_strchr(flags, 't')))
		liste = ft_sort_reverse(liste);
	else if (ft_strchr(flags, 'r') && ft_strchr(flags, 't'))
		return (liste = ft_sort_reversetime_arg(liste));
	else if (ft_strchr(flags, 't'))
		liste = ft_sort_by_time(liste);
	else if (ft_strchr(flags, 'a'))
		liste = ft_sort_by_ascii(liste);
	else if (ft_strchr(flags, 'r'))
		liste = ft_sort_reverse(liste);
	else
		liste = ft_sort_by_ascii(liste);
	return (liste);
}

t_list			*ft_sort_list(t_list *validarg, char *flags)
{
	if (ft_strchr(flags, 'r') && !(ft_strchr(flags, 't')))
		validarg = ft_sort_reverse_norm(validarg);
	else if (ft_strchr(flags, 'r') && (ft_strchr(flags, 't')))
		validarg = ft_sort_reverse_timenorm(validarg);
	else
		validarg = ft_sort_by_ascii_arg(validarg);
	return (validarg);
}

t_list			*ft_sort_by_ascii_arg(t_list *liste)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		tmp3;

	tmp = liste;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (ft_sort_ascii(tmp->content, tmp2->content) != 1)
			{
				tmp3.content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3.content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (liste);
}

t_list			*ft_sort_by_ascii(t_list *liste)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		tmp3;

	tmp = liste;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_sort_ascii((((t_ls*)tmp->content)->name),
							(((t_ls*)tmp2->content)->name)) != 1))
			{
				tmp3.content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3.content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (liste);
}

t_list			*ft_sort_reverse_norm(t_list *liste)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		tmp3;

	tmp = liste;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_sort_r_ascii((tmp->content),
				(tmp2->content)) != 1))
			{
				tmp3.content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3.content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (liste);
}


t_list			*ft_sort_reverse(t_list *liste)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		tmp3;

	tmp = liste;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_sort_r_ascii((((t_ls*)tmp->content)->name),
				(((t_ls*)tmp2->content)->name))) != 1)
			{
				tmp3.content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3.content;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (liste);
}
