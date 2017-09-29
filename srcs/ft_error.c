/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:09:00 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 16:13:45 by apissier         ###   ########.fr       */
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
//	free(arglist);
	return (tmplst);
}

long			ft_get_error(int error, const char *letter)
{
	if (error == 1)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putstr_fd(letter, 2);
		ft_putstr_fd("\nusage: ft_ls [-"LS_FLAGS"] [file ...]\n", 2);
		exit(1);
	}
	else if (letter)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(letter, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else
	{
		ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	return (0);
}
