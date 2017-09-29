/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:05:54 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 19:59:32 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list				*ft_createandread_list(t_list *va, char *flags)
{
	t_list			*newliste;
	t_list			*tmp;
	t_ls			*gi;
	DIR				*path;
	struct dirent	*infostruct;

	newliste = NULL;
	if (!(path = opendir(va->content)))
	{
		ft_get_error(0, (char*)va->content);
		return (newliste);
	}
	while ((infostruct = readdir(path)))
	{
		if (!(gi = ft_memalloc(sizeof(t_ls))) || ft_get_info(gi, va->content,
		infostruct, flags) || !(tmp = ft_lstnew(gi, sizeof(t_ls))))
			ft_get_error(0, 0);
		else
		{
			ft_memdel((void**)&gi);
			ft_lstaddend(&newliste, tmp);
		}
	}
	(void)closedir(path);
	return (newliste);
}

t_list				*ft_ls_no_arg(void)
{
	t_list			*tmp;
	t_list			*lst;
	char			*path;

	path = ".";
	tmp = ft_lstnew(path, 2);
	((char*)tmp->content)[1] = '\0';
	ft_lstaddend(&lst, tmp);
	return (lst);
}

int					ft_ls_recursive(char *validarg, char *flags)
{
	t_list			*folderlist;
	t_list			*filelist;
	char			*newpath;

	folderlist = NULL;
	filelist = NULL;
	folderlist = ft_get_folder_rec(validarg, flags);
	filelist = ft_get_file_rec(validarg, flags);
	ft_print(filelist, flags);
	while (folderlist)
	{
		newpath = ft_strjoinmulti(validarg, "/", ((t_ls*)folderlist->content)->name, "");
		ft_printf("\n%s:\n", newpath);
		ft_ls_recursive(newpath, flags);
		folderlist = folderlist->next;
	}
	return (0);
}

int					*ft_ls(char *flags, t_list *validarg)
{
	int				foldername;
	int				newline;
	t_list			*tmp;
	t_list			*print;

	foldername = 0;
	newline = 0;
	if (validarg && validarg->next)
		foldername = 1;
	while (validarg && validarg != NULL)
	{
		if (newline == 1)
			ft_putchar('\n');
		if (foldername == 1)
			ft_printf("%s:\n", ((char*)validarg->content));
			//ft_print_foldername((char*)validarg->content);
		tmp = (ft_createandread_list(validarg, flags));
		validarg = validarg->next;
		newline = 1;
		print = ft_check_sort(tmp, flags);
		ft_print(print, flags);
	}
	return (0);
}

int					main(int ac, char **av)
{
	int				i;
	char			flags[ft_strlen(LS_FLAGS) + 1];
	t_list			*arglist;
	t_list			*validarg;

	i = 1;
	arglist = NULL;
	validarg = NULL;
	ft_bzero(&flags, ft_strlen(LS_FLAGS) + 1);
	arglist = ft_get_list_arg(ac, av);
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1])
			ft_get_flags(flags, av[i] + 1);
		else
			break ;
		i++;
	}
	if (ft_strchr(flags, 'R'))
		ft_rec_parsing(flags, arglist);
	else
		validarg = ft_ls_parsing(flags, arglist, 0);
	return (0);
}
