/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:20:48 by apissier          #+#    #+#             */
/*   Updated: 2017/09/28 20:23:30 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		ft_print_noarg(t_list *tmp)
{
	struct stat	buffer;

	if ((lstat((((t_ls*)tmp->content)->name), &buffer) == 0) &&
			(S_ISDIR(buffer.st_mode)))
		ft_printf("\033[36m\033[1m%s\033[0m", ((t_ls*)tmp->content)->name);
	else if ((lstat((((t_ls*)tmp->content)->name), &buffer) == 0) &&
			(buffer.st_mode & S_IXUSR))
		ft_printf("\033[31m%s\033[0m", ((t_ls*)tmp->content)->name);
	else
		ft_printf("%s", (((t_ls*)tmp->content)->name));
}

void		ft_print_goodtime(t_list *tmp, char *flags)
{
	if (ft_strchr(flags, 'u'))
		ft_cut_time(((char *)ctime(&((t_ls*)tmp->content)->atime)));
	else if (ft_strchr(flags, 'U'))
		ft_cut_time(((char *)ctime(&((t_ls*)tmp->content)->ctime)));
	else
		ft_cut_time(((char *)ctime(&((t_ls*)tmp->content)->time)));
}

void		ft_print_name(t_list *tmp)
{
	if (tmp)
	{
		if ((((t_ls*)tmp->content)->foldercolor) == 1)
			ft_printf("\033[36m\033[1m%s\033[0m", ((t_ls*)tmp->content)->name);
		else if ((((t_ls*)tmp->content)->readlink))
			ft_printf("\033[35m%s\033[0m", ((t_ls*)tmp->content)->name);
		else if ((((t_ls*)tmp->content)->peric) == 1)
			ft_printf("\033[43m\033[34m%s\033[0m", ((t_ls*)tmp->content)->name);
		else if ((((t_ls*)tmp->content)->perib) == 1)
			ft_printf("\033[46m\033[34m%s\033[0m", ((t_ls*)tmp->content)->name);
		else if ((((t_ls*)tmp->content)->isuid) == 1)
			ft_printf("\033[41m\033[30m%s\033[0m", ((t_ls*)tmp->content)->name);
		else if ((((t_ls*)tmp->content)->exec) == 1)
			ft_printf("\033[31m%s\033[0m", ((t_ls*)tmp->content)->name);
		else
			ft_printf("%s", (((t_ls*)tmp->content)->name));
	}
}

void		ft_print_majorminor(t_list *tmp, t_pad *pad)
{
	if ((((t_ls*)tmp->content)->major) != -1)
	{
		ft_paddingtool(pad->major, (ft_intlen((((t_ls*)tmp->content)->major))));
		ft_printf("%d, ", (((t_ls*)tmp->content)->major));
		ft_paddingtool(pad->size, (ft_intlen((((t_ls*)tmp->content)->size))));
		ft_printf("%d", ((((t_ls*)tmp->content)->size)));
	}
	else
	{
		if (((((t_ls*)tmp->content)->major) == -1) && (pad->ismajor == 1))
			ft_putstr("      ");
		else
			ft_paddingtool(pad->size, (ft_intlen((((t_ls*)tmp->content)
			->size))));
		ft_printf("%d", ((((t_ls*)tmp->content)->size)));
	}
}

void		ft_cut_time(char *tmp)
{
	int		i;
	int		j;
	char	*tmp2;

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
	ft_printf("%s ", tmp2);
}
