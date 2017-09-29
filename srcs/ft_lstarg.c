/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 09:28:37 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 16:41:48 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list			*ft_get_list_arg(int ac, char **av)
{
	int			i;
	t_list		*lst;
	t_list		*tmp;
	int			noarg;

	i = 1;
	noarg = 0;
	lst = NULL;
	tmp = NULL;
	while (i < ac)
	{
		if (av[i][0] != '-')
		{
			tmp = ft_lstnew(av[i], ft_strlen(av[i]) + 1);
			((char*)tmp->content)[ft_strlen(av[i])] = '\0';
			ft_lstaddend(&lst, tmp);
			noarg++;
		}
		i++;
	}
	if (noarg == 0)
		lst = ft_ls_no_arg();
	return (lst);
}
