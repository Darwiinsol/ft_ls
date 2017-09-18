/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:20:16 by apissier          #+#    #+#             */
/*   Updated: 2017/09/18 15:07:17 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_ls.h"

static void     ft_modeguy(struct stat stats, char *mode)
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

static void     ft_majorminor(struct stat *stats, t_ls *info)
{
    int         major;

    major = stats->st_rdev;
    if (stats->st_rdev)
    {
        while (major / 256 > 0)
            major = major / 256;
        info->size = stats->st_rdev % 256;
        info->major = major;
    }       
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
int				    ft_get_info(t_ls *info, char *path, struct dirent *infostruct, char *flags)
{
    struct stat     stats;
    struct passwd   *psswd;
    struct group    *grp;

    if (!path)
       return ((int)ft_get_error(0, 0));
    info->path = ft_strdup(path);
    info->flags = flags; 
    info->name = ft_strdup(infostruct->d_name);
    if ((ft_strchr((const char*)flags, 't')) || (ft_strchr((const char *)flags, 'l')) 
        || (ft_strchr((const char*)flags, 'S')))
    {
        if (lstat((ft_strjoinmulti("", path, "/", infostruct->d_name)), &stats) != '\0')
            return (1);
        else
        {
            ft_get_info_norm(stats, info, path, infostruct);
            psswd = getpwuid(stats.st_uid);
            grp = getgrgid(stats.st_gid);
            info->owner = ft_strdup(psswd->pw_name);
            info->group = ft_strdup(grp->gr_name);
        }
    }
    return (0);
}

void                ft_get_info_norm(struct stat stats, t_ls *info, char *path, struct dirent *infostruct)
{
    char            buf[FNMAXLEN];
    size_t          len;

    info->links = stats.st_nlink;
    info->size = stats.st_size;
    info->blocks = stats.st_blocks;
    info->time = stats.st_mtime;
    info->atime = stats.st_atime;
    info->ctime = stats.st_ctime;

    if ((len = readlink(ft_strjoinmulti("", path, "/", infostruct->d_name), buf, sizeof(buf))) != (size_t)-1)
    {
        buf[len] = '\0';
        info->readlink = ft_strdup(buf); 
    }
    ft_modeguy(stats, info->mode);
    if ((S_ISCHR(stats.st_mode)) || (S_ISBLK(stats.st_mode)))
        ft_majorminor(&stats, info);
    else
        info->major = -1;
}