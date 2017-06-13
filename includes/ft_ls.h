/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:16:00 by apissier          #+#    #+#             */
/*   Updated: 2017/06/07 17:00:09 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS
# define FT_LS
# include <pwd.h>
# include <grp.h>
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <time.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"
# define LS_FLAGS "larRt"
# define FNMAXLEN 255

typedef struct			s_flag
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
    int         verify;
	int			error;
}						t_flag;

typedef struct			s_ls
{
	char		*name;
	char		*user;
	long		time;
	int			links;
	long long	size;
	long long	blocks;
	char		*group;
	char		linkpath;
	char		mode[15];

}						t_ls;

t_list					*ft_sort_by_ascii(t_list *liste);
t_list					*ft_check_sort(t_list *liste, char *flags, t_ls *info);
t_list					*ft_sort_reverse(t_list *liste);
t_list					*ft_sort_by_time(t_list *liste);
t_list                  *ft_sort_reverse_time(t_list *liste);
int						ft_get_info(t_ls *info, char *infostruct, const char *path);
void					ft_ls_no_arg(char *flags);
//int						ft_l_case(/*t_list liste, char *flags,*/ t_ls *info);
int						ft_l_case(t_ls *info, char *infostruct, const char *path);

#endif
