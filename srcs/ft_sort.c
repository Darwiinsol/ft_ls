/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:17:35 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 15:29:44 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list			*ft_sort_by_ascii(t_list *liste)
{
	t_list		*tmp;
	t_list		*tmp2;
	t_list		tmp3;

	tmp = liste;
	while (tmp)
	
		tmp2 = tmp->next;
		while (tmp2)
		{
			if ((ft_sort_ascii((((t_ls*)tmp->content)->name),(((t_ls*)tmp2->content)->name)) != 1))
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
