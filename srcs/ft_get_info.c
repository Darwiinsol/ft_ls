/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:20:16 by apissier          #+#    #+#             */
/*   Updated: 2017/05/31 14:31:17 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void     modeguy(struct stat stats, char *mode)
{
    if (S_ISCHR(stats.st_mode))
        *mode++ = 'c';
    else if (S_ISFIFO(stats.st_mode))
        *mode++ = 'p';
    else if (S_ISDIR(stats.st_mode))
        *mode++ = 'd';
    else if (S_ISLNK(stats.st_mode))
        *mode++ = 'l';
    else if (S_ISBLK(stats.st_mode))
        *mode++ = 'b';
    else if (S_ISSOCK(stats.st_mode))
        *mode++ = 's';
    else if (S_ISREG(stats.st_mode))
        *mode++ = '-';
    *mode++ = (stats.st_mode & S_IRUSR ? 'r' : '-');
    *mode++ = (stats.st_mode & S_IWUSR ? 'w' : '-');
    *mode++ = (stats.st_mode & S_IXUSR ? 'x' : '-');
    *mode++ = (stats.st_mode & S_IRGRP ? 'r' : '-');
    *mode++ = (stats.st_mode & S_IWGRP ? 'w' : '-');
    *mode++ = (stats.st_mode & S_IXGRP ? 'x' : '-');
    *mode++ = (stats.st_mode & S_IROTH ? 'r' : '-');
    *mode++ = (stats.st_mode & S_IWOTH ? 'w' : '-');
    *mode = (stats.st_mode & S_IXOTH ? 'x' : '-');
    if (stats.st_mode & S_ISVTX)
        *mode = 't';
}
/*
static int          ft_l_case_assist(t_ls *info)
{
	char			buf[FNMAXLEN + 1];
	struct stat		sym_stat;
	int				cc;

	ft_bzero(&buf, FNMAXLEN + 1);
	cc = readlink('.', buf, FNAMXLEN);
	info->linkpath = (cc == -1 : NULL ? ft_strdu(buf));
	
}
*/
int					ft_get_info(t_ls *info, char *infostruct, const char *path)
{
	struct	stat	stats;

	lstat(path, &stats);
	info->name = infostruct;
	info->time = stats.st_mtime;
	return (0);
}

int                 ft_l_case(t_ls *info, char *infostruct, const char *path)
{
    struct stat		stats;
    struct passwd   *pwd;
    struct group	*grg;

    lstat(path, &stats);
    modeguy(stats, info->mode);
    info->links = stats.st_nlink;
    info->size = stats.st_size;
    info->blocks = stats.st_blocks;
    info->time = stats.st_mtime;
    pwd = getpwuid(stats.st_uid);
    grg = getgrgid(stats.st_gid);
    info->name = ft_strdup(pwd->pw_name);
    info->group = ft_strdup(grg->gr_name);
    return (0);//ft_l_case_assist(info));
}
