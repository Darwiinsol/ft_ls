/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:09:00 by apissier          #+#    #+#             */
/*   Updated: 2017/09/15 08:28:11 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list			*ft_check_error_arg(t_list *arglist)
{
	struct stat buf;
	t_error		*errorlst;
	t_list		*tmp;
	t_list		*tmp2;
	t_list		*tmplst;

	tmplst = NULL;
	tmp = arglist;
	while (tmp)
	{
		if ((lstat(tmp->content, &buf) == -1))
		{
			errorlst = ft_memalloc(sizeof(t_error));
			errorlst->name = ft_strdup(tmp->content);
			errorlst->errnbr = errno;
			tmp2 = ft_lstnew(errorlst, sizeof(t_error));
			ft_memdel((void**)&errorlst);
			ft_lstaddend(&tmplst, tmp2);
		}
		tmp = tmp->next;
	}
	return (tmplst);
}
