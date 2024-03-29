/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:17:35 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 18:04:07 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_sort_nbr(long a, long b)
{
	if (a && b)
	{
		if (a < b)
			return (0);
	}
	return (1);
}

static int		ft_sort_reverse_nbr(long a, long b)
{
	if (a && b)
	{
		if (a > b)
			return (0);
	}
	return (1);
}

t_list			*ft_sort_reversetime_arg(t_list *liste)
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
			if ((((t_ls*)tmp->content)->time) > (((t_ls*)tmp2->content)->time))
			{
				tmp3.content = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = tmp3.content;
			}
			if ((((t_ls*)tmp->content)->time) == (((t_ls*)tmp2->content)->time))
			{
				if ((ft_sort_r_ascii(((t_ls*)tmp->content)->name,
								((t_ls*)tmp2->content)->name)) != 1)
				{
					tmp3.content = tmp->content;
					tmp->content = tmp2->content;
					tmp2->content = tmp3.content;
				}
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (liste);
}

t_list			*ft_sort_by_time(t_list *liste)
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
			if ((((t_ls*)tmp->content)->time) == (((t_ls*)tmp2->content)->time))
			{
				if ((ft_sort_ascii((((t_ls*)tmp->content)->name),
								(((t_ls*)tmp2->content)->name)) != 1))
				{
					tmp3.content = tmp->content;
					tmp->content = tmp2->content;
					tmp2->content = tmp3.content;
				}
			}
			if ((ft_sort_nbr((((t_ls*)tmp->content)->time),
							(((t_ls*)tmp2->content)->time)) != 1))
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

t_list			*ft_sort_by_time_arg(t_list *liste)
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
			if ((((t_ls*)tmp->content)->time) == (((t_ls*)tmp2->content)->time))
			{
				if (ft_sort_ascii(tmp->content, tmp2->content) != 1)
				{
					tmp3.content = tmp->content;
					tmp->content = tmp2->content;
					tmp2->content = tmp3.content;
				}
			}
			if ((ft_sort_nbr((((t_ls*)tmp->content)->time),
							(((t_ls*)tmp2->content)->time)) != 1))
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

t_list			*ft_sort_reverse_time(t_list *liste)
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
			if ((((t_ls*)tmp->content)->time) == (((t_ls*)tmp2->content)->time))
			{
				if ((ft_sort_r_ascii((((t_ls*)tmp->content)->name),
								(((t_ls*)tmp2->content)->name)) != 1))
				{
					tmp3.content = tmp->content;
					tmp->content = tmp2->content;
					tmp2->content = tmp3.content;
				}
			}
			if ((ft_sort_reverse_nbr((((t_ls*)tmp->content)->time),
							(((t_ls*)tmp2->content)->time)) != 1))
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

t_list			*ft_sort_reverse_timenorm(t_list *liste)
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
			if ((((t_ls*)tmp->content)->time) == (((t_ls*)tmp2->content)->time))
			{
				if ((ft_sort_r_ascii((tmp->content),
								(tmp2->content))) != 1)
				{
					tmp3.content = tmp->content;
					tmp->content = tmp2->content;
					tmp2->content = tmp3.content;
				}
			}
			if ((ft_sort_reverse_nbr((((t_ls*)tmp->content)->time),
							(((t_ls*)tmp2->content)->time)) != 1))
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