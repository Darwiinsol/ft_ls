/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:16:00 by apissier          #+#    #+#             */
/*   Updated: 2017/09/18 15:55:01 by apissier         ###   ########.fr       */
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
# define LS_FLAGS "larRtS"
# define FNMAXLEN 255
# define MODE 15

typedef struct			s_flag
{
	int					l;
	int					R;
	int					a;
	int					r;
	int					t;
    int					verify;
	int					error;
}						t_flag;

typedef struct			s_ls
{
	char				*name;
	char				*owner;
	char				*path;
	char				*flags;
	long				time;
	long				atime;
	long				ctime;
	int					links;
	int					major;
	long long			size;
	long long			blocks;
	char				*readlink;
	char				*group;
	char				linkpath;
	char				mode[MODE];

}						t_ls;

typedef struct			s_error
{
	char				*name;
	int					errnbr;
	char				*path;
}						t_error;

typedef struct			s_pad
{
	int					iscontent;
	int					links;
	int					owner;
	int					group;
	int					size;
	int					major;
	int					ismajor;
}						t_pad;

int						*ft_ls(char *flags, t_list *validarg);
long					ft_get_error(int error, const char *letter);
t_list					*ft_sort_by_ascii(t_list *liste);
t_list					*ft_check_sort(t_list *liste, char *flags);
t_list					*ft_sort_reverse(t_list *liste);
t_list					*ft_sort_by_time(t_list *liste);
t_list                  *ft_sort_reverse_time(t_list *liste);
t_list					*ft_sort_list(t_list *validarg, char *flags);
t_list					*ft_get_list_arg(int ac, char **av);
t_list					*ft_get_folder(t_list *arglist);
t_list					*ft_get_file(t_list *arglist);
t_list					*ft_ls_no_arg(void);
t_list					*ft_ls_parsing(char *flags, t_list *arglist, int recursive);
t_list					*ft_check_error_arg(t_list *arglist);
t_pad					*ft_pad_l(t_list *print, t_pad *pad);
//int						*ft_ls(char *flags, t_list *validarg);
int						ft_get_info_arg(t_ls *info, char *infostruct, const char *path);
int						ft_get_info(t_ls *info, char *path, struct dirent *infostruc, char *flags);
void               		ft_get_info_norm(struct stat stats, t_ls *info, char *path, struct dirent *infostruct);
//void					ft_ls_no_arg(char *flags);
void					ft_ls_arg(int ac, char **av, int i, char *flags);
void					ft_print(t_list *print, char *flags);
void					ft_print_arg_error(t_list *errorarg);
void					ft_print_list(t_list *list);
void					ft_print_foldername(char *str);
//int						ft_l_case(/*t_list liste, char *flags,*/ t_ls *info);
int						ft_l_case(t_ls *info, char *infostruct, const char *path);

#endif
