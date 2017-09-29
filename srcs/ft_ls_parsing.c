/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:01:50 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 16:57:20 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list			*ft_get_folder(t_list *arglist)
{
	struct stat	buffer;
	t_list		*tmp;
	t_list		*tmp2;
	t_list		*tmplist;

	tmp = arglist;
	tmplist = NULL;
	while (tmp)
	{
		if ((lstat(tmp->content, &buffer) == 0) && (S_ISDIR(buffer.st_mode)))
		{
			tmp2 = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1);
			((char*)tmp->content)[ft_strlen(tmp->content)] = '\0';
			ft_lstaddend(&tmplist, tmp2);
		}
		tmp = tmp->next;
	}
	return (tmplist);
}

t_list			*ft_get_file(t_list *arglist)
{
	struct stat buffer;
	t_list		*tmp;
	t_list		*tmp2;
	t_list		*tmplist;

	tmp = arglist;
	tmplist = NULL;
	while (tmp)
	{
		if ((lstat(tmp->content, &buffer) == 0) && (S_ISREG(buffer.st_mode)))
		{
			tmp2 = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1);
			((char*)tmp->content)[ft_strlen(tmp->content)] = '\0';
			ft_lstaddend(&tmplist, tmp2);
		}
		tmp = tmp->next;
	}
	return (tmplist);
}

t_list			*ft_ls_parsing(char *flags, t_list *arglist, int recursive)
{
	t_list		*validarg;
	t_list		*errorarg;
	t_list		*filelist;

	validarg = NULL;
	errorarg = NULL;
	filelist = NULL;
	errorarg = ft_check_error_arg(arglist);
	errorarg = ft_sort_by_ascii(errorarg);
	ft_print_arg_error(errorarg);
	validarg = ft_get_folder(arglist);
	validarg = ft_sort_list(validarg, flags);
	filelist = ft_get_file(arglist);
	filelist = ft_sort_list(filelist, flags);
	ft_print_list(filelist);
	if (recursive == 1)
		return (validarg);
	else
	{
		ft_ls(flags, validarg);
		return (validarg);
	}
}
