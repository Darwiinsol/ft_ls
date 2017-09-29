/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_rec_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:17:42 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 20:03:32 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*ft_get_rec_norm(t_list *filelist, char *flags,
					char *validarg, struct dirent *infostruct)
{
	t_ls			*inf;
	t_list			*tmp;

	if (!(inf = ft_memalloc(sizeof(t_ls)))
		|| ft_get_info(inf, validarg, infostruct, flags)
		|| (!(tmp = ft_lstnew(inf, sizeof(t_ls)))))
		ft_get_error(0, infostruct->d_name);
	else
	{
		ft_lstaddend(&filelist, tmp);
		ft_memdel((void**)&inf);
	}
	return (filelist);
}

t_list				*ft_get_file_rec(char *validarg, char *flags)
{
	struct dirent	*infostr;
	DIR				*dirpath;
	t_list			*filelist;

	filelist = NULL;
	if ((dirpath = opendir(validarg)))
	{
		while ((infostr = readdir(dirpath)))
		{
			if ((!(ft_strchr(flags, 'a')) && infostr->d_name[0] == '.'))
				;
			else
				filelist = ft_get_rec_norm(filelist, flags, validarg, infostr);
		}
		(void)closedir(dirpath);
		return (ft_check_sort(filelist, flags));
	}
	else
	{
		ft_get_error(4, validarg);
		return (filelist);
	}
}

t_list				*ft_get_folder_rec(char *validarg, char *flags)
{
	struct dirent	*info;
	struct stat     buffer;
	DIR				*dirpath;
	t_ls			*pls;
	t_list			*tmp;
	t_list			*folderlist;

	tmp = NULL;
	folderlist = NULL;
	if ((dirpath = opendir(validarg)))
	{
		while ((info = readdir(dirpath)))
		{
			if ((lstat(ft_strjoinmulti(validarg, "/", info->d_name, ""),
				&buffer) == 0) & ((buffer.st_mode & S_IFMT) == S_IFDIR)
				& !((info->d_name[0]) == '.'))
			{

				pls = ft_memalloc(sizeof(t_ls));
				pls->name = ft_strdup(info->d_name);
				pls->time = buffer.st_mtime;
				tmp = ft_lstnew(pls, sizeof(t_ls));
				ft_lstaddend(&folderlist, tmp);
			}
		}
		closedir(dirpath);
		return (ft_check_sort(folderlist, flags));
	}
	return (NULL);
}

void				ft_rec_parsing(char *flags, t_list *arglist)
{
	t_list			*validarg;

	validarg = NULL;
	validarg = ft_ls_parsing(flags, arglist, 1);
	while (validarg)
	{
		ft_ls_recursive((char*)validarg->content, flags);
		validarg = validarg->next;
	}
}
