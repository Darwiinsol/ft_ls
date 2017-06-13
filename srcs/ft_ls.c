/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:05:54 by apissier          #+#    #+#             */
/*   Updated: 2017/06/13 14:25:29 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static long				ft_get_error(int error, const char *letter)
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
static char				*ft_cut(char *tmp)
{
	int i;
	int j;
	char *tmp2;

	i = 0;
	j = 0;

	tmp2 = (char *)ft_memalloc(sizeof(char *));
	while (tmp[i])
	{
		while (i < 4 && tmp[i])
			i++;
		while (i < 16 && tmp[i])
			tmp2[j++] = tmp[i++];
		i++;
	}
	tmp2[j] = '\0';
	return (tmp2);
}

static void				ft_printlist(t_list *content, char *flags)
{
	t_list	*tmp;
	char	*tmp2;

	tmp = content;
	while (tmp)
	{
		if ((ft_strchr(flags, 'l')) && (((t_ls*)tmp->content)->name[0]) != '.')
		{
			tmp2 = ((char *)ctime(&((t_ls*)tmp->content)->time));
			ft_printf("%s %i %s %s %lld %s %s\n",((t_ls*)tmp->content)->mode, ((t_ls*)tmp->content)->links, ((t_ls*)tmp->content)->user, ((t_ls*)tmp->content)->group, ((t_ls*)tmp->content)->size, ft_cut(((char *)ctime(&((t_ls*)tmp->content)->time))), ((t_ls*)tmp->content)->name);	
		}
        else if ((ft_strchr(flags, 'l')) && ft_strchr(flags, 'a'))
        {
            tmp2 = ((char *)ctime(&((t_ls*)tmp->content)->time));
            ft_printf("%s %i %s %s %lld %s %s\n",((t_ls*)tmp->content)->mode, ((t_ls*)tmp->content)->links, ((t_ls*)tmp->content)->user, ((t_ls*)tmp->content)->group, ((t_ls*)tmp->content)->size, ft_cut(((char *)ctime(&((t_ls*)tmp->content)->time))), ((t_ls*)tmp->content)->name);
			}
		else if (ft_strchr(flags, 'a'))
			ft_putendl((((t_ls*)tmp->content)->name));
        else
        {
            if (((t_ls*)tmp->content)->name[0] != '.')
                ft_putendl((((t_ls*)tmp->content)->name));
        }
		tmp = tmp->next;
	}
}

t_list               *ft_check_sort(t_list *liste, char *flags)
{
	/*ft_l_case(liste, flags, info, path);*/ 
	if (ft_strchr(flags, 'a') && ft_strchr(flags, 'r') && !(ft_strchr(flags, 't')))
		liste = ft_sort_reverse(liste);
	else if (ft_strchr(flags, 'r') && ft_strchr(flags, 't'))
        return (liste = ft_sort_reverse_time(liste));
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

void				ft_ls_arg(int ac, char **av, int i, char *flags)
{
	t_list			*liste;
	t_list			*tmp;

	liste = NULL;
	tmp = NULL;
	while (i < ac)
	{
		if (!(tmp = ft_lstnew(av[i], ft_strlen(av[i]) + 1)))
			ft_get_error(0, 0);
		if (!liste)
			liste = tmp;
		else
			ft_lstaddend(&liste, tmp);
		i++;
	}
	liste = ft_check_sort(liste, flags);
}

void				ft_ls_no_arg(char *flags)
{
	t_list			*liste;
	t_list			*tmp;
	t_ls			*info;
	DIR				*path;
	struct dirent	*infostruct;

	liste = NULL;
//	if (ft_strchr(flags, 'l'))
	//	return ;
	path = opendir(".");
	if (path == NULL)
		return ; // check ft_check_error ??
	while ((infostruct = readdir(path)))
	{
		if (!(info = ft_memalloc(sizeof(t_ls))))
			ft_get_error(0, 0);
		//	info->name = ft_strdup(infostruct->d_name);
		if (ft_strchr(flags, 'l'))
			ft_l_case(info, ft_strdup(infostruct->d_name), ft_strnjoin(2, "./", infostruct->d_name));
		else
			ft_get_info(info, ft_strdup(infostruct->d_name), ft_strnjoin(2, "./", infostruct->d_name));
		tmp = ft_lstnew(info, sizeof(t_ls));
		ft_memdel((void**)&info);
		ft_lstaddend(&liste, tmp);
	}
//	if (ft_strchr(flags, 'l'))
	//	ft_l_case(info, ft_strdup(infostruct->d_name), ft_strnjoin(3, path, "/", infostruct->d_name));
	liste = ft_check_sort(liste, flags);
	ft_printlist(liste, flags);
}
/*
static t_flag				ft_get_flag(char **av, t_flag b, int i)
{
	int				y;

	y = 0;
	while (av[i][y])
	{
		y++;
		(av[i][y] == 'l' ? (b.l = 1) : (b.verify = 0));
		(av[i][y] == 'R' ? (b.R = 1) : (b.verify = 0));
		(av[i][y] == 'a' ? (b.a = 1) : (b.verify = 0));
		(av[i][y] == 'r' ? (b.r = 1) : (b.verify = 0));
		(av[i][y] == 't' ? (b.t = 1) : (b.verify = 0));
	}
	((b.l == 0 && b.R == 0 && b.a == 0 && b.r == 0 && b.t == 0) ? (b.verify = 1) : (b.verify = 0));
	if (b.verify == 1 && av[1][0] == '-' && av[1][1] != '-')
	{
		b.error = 1;
		ft_putstr("Try 'ls --h' for more information.\n");
	}
	return (b);
}
*/

static void			ft_get_flags(char *flags, char *format)
{
	int				flags_count;
	
	flags_count = ft_strlen(flags);
	while (*format)
	{
		format++;
		if (ft_strchr(LS_FLAGS, *format))
		{
			if (!(ft_strchr(flags, *format)))
				flags[flags_count++] = *format;
		}
		else
			ft_get_error(1, (char[2]){(*format), '\0'});
		//format++;
	}
} 

int					main(int ac, char **av)
{
	int				i;
	char			flags[ft_strlen(LS_FLAGS) + 1];
//	t_flag			b;

	i = 1;
	ft_bzero(&flags, ft_strlen(LS_FLAGS) + 1);
	//b = (t_flag){0, 0, 0, 0, 0, 0, 0};
	while (i < ac)
    {
		if (av[i][0] == '-' && av[i][1])
			ft_get_flags(flags, av[i]);			
//b = ft_get_flag(av, b, i);
		else
			break ;
		i++;
    }
	if (i < ac)
		ft_ls_arg(ac, av, i, flags);
	else
	{
		//	if (ft_strchr(flags, 'l')
		//ft_case_l(content, av, b);
		ft_ls_no_arg(flags);
	}
	return (0);
}
