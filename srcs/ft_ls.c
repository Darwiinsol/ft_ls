/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 12:05:54 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 18:29:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void				ft_printlist(t_list *content, t_flag b)
{
	t_list *tmp;

	tmp = content;
	while (tmp)
	{
		if (b.t == 0 && b.r == 0 && b.a == 0 && b.R == 0 && b.l == 0)
		{		
			if (((t_ls*)tmp->content)->name[0] != '.')
				ft_putendl((((t_ls*)tmp->content)->name));
		}
		else if (b.a == 1)
			ft_putendl((((t_ls*)tmp->content)->name));
		tmp = tmp->next;
	}
}

t_list          *ft_sort_by_ascii(t_list *liste)
{
    t_list      *tmp;
    t_list      *tmp2;
    t_list      tmp3;

    tmp = liste;
    while (tmp)
	{
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


t_list               *ft_check_sort(t_list *liste, t_flag b)
{
	 if (b.t == 0 && b.r == 0 && b.a == 0 && b.R == 0 && b.l == 0 && b.verify == 0)
		 liste = ft_sort_by_ascii(liste);
	 // else if (b.t == 1)
    //  return (content = ft_sort_by_time(content, b));
//  else if (b.r == 1)
    //  return (content = ft_sort_by_r(content, b));
	//  return (0);
	return (liste);
}

static void				ft_ls_no_arg(t_flag b)
{
	t_list			*liste;
	t_list			*tmp;
	t_ls			*info;
	DIR				*path;
	struct dirent	*infostruct;

	liste = NULL;
	if (b.l == 1)
		return ;
	path = opendir(".");
	if (path == NULL)
		return ; // check ft_check_error ??
	while ((infostruct = readdir(path)))
	{
		if (!(info = ft_memalloc(sizeof(t_ls))))
			break ; // a modifier par ft_check_error(....)
		info->name = ft_strdup(infostruct->d_name);
		tmp = ft_lstnew(info, sizeof(t_ls));
		ft_memdel((void**)&info);
		ft_lstaddend(&liste, tmp);
	}
	liste = ft_check_sort(liste, b);
	ft_printlist(liste, b);
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
		if (ft_strchr(LS_FLAGS, *format))
		{
			if (!(ft_strchr(flags, *format)))
				flags[flags_count++] = *format;
		}
		else
			printf("error"); //gerer les erreurs avec un ft_error
		format++;
	}
} 

int					main(int ac, char **av)
{
	int				i;
	char			flags[ft_strlen(LS_FLAGS) + 1];
	t_flag			b;
	
	i = 1;
	ft_bzero(&flags, ft_strlen(LS_FLAGS) + 1)
	//b = (t_flag){0, 0, 0, 0, 0, 0, 0};
	while (av[i])
    {
		if (av[i][0] == '-' && av[i][1])
			ft_get_flags(flags, av[i + 1]);
			//b = ft_get_flag(av, b, i);
		else
			break ;
		i++;
    }
	if (i < ac)
		return (0);
//	ft_ls_with_arg(ac, av, &b, i);
	else if (b.error == 0)
	{
/*		if (b.l == 1)
		ft_case_l(content, av, b);*/
		ft_ls_no_arg(b);
	}
	return (0);
}
