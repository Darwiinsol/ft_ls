/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:16:00 by apissier          #+#    #+#             */
/*   Updated: 2017/09/29 18:49:23 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS
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
# define LS_FLAGS "larRtSuU"
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
	int					foldercolor;
	int					exec;
	int					isuid;
	int					peric;
	int					perib;

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
void					ft_get_flags(char *flags, char *format);
t_list					*ft_createandread_list(t_list *va, char *flags);
t_list					*ft_sort_by_ascii(t_list *liste);
t_list					*ft_sort_by_ascii_arg(t_list *liste);
t_list					*ft_check_sort(t_list *liste, char *flags);
t_list					*ft_sort_reverse(t_list *liste);
t_list					*ft_sort_reverse_norm(t_list *liste);
t_list					*ft_sort_reverse_timenorm(t_list *liste);
t_list					*ft_sort_reversetime_arg(t_list *liste);
t_list					*ft_sort_by_time(t_list *liste);
t_list					*ft_sort_by_time_arg(t_list *liste);
t_list					*ft_sort_reverse_time(t_list *liste);
t_list					*ft_sort_list(t_list *validarg, char *flags);
t_list					*ft_get_list_arg(int ac, char **av);
t_list					*ft_get_folder(t_list *arglist);
t_list					*ft_get_file(t_list *arglist);
t_list					*ft_ls_no_arg(void);
t_list					*ft_ls_parsing(char *flags, t_list *arglist,
		int recursive);
t_list					*ft_check_error_arg(t_list *arglist);
t_pad					*ft_pad_l(t_list *print, char *flags, t_pad *pad);
void					ft_paddingtool(int pad, int len);
void					ft_cut_time(char *tmp);
int						ft_get_info_arg(t_ls *info, char *infostruct,
		const char *path);
int						ft_get_info(t_ls *info, char *path,
		struct dirent *infostruc, char *flags);
void					ft_get_info_norm(struct stat stats, t_ls *info,
		char *path, struct dirent *infostruct);
void					ft_getmax_l(t_list *print, char *flags, t_pad *pad);
void					ft_ls_arg(int ac, char **av, int i, char *flags);
void					ft_print(t_list *print, char *flags);
void					ft_print_noarg(t_list *tmp);
void					ft_print_arg_error(t_list *errorarg);
void					ft_print_list(t_list *list);
void					ft_print_foldername(char *str);
void					ft_print_goodtime(t_list *tmp, char *flags);
void					ft_print_name(t_list *tmp);
void					ft_print_majorminor(t_list *tmp, t_pad *pad);
int						ft_l_case(t_ls *info, char *infostruct,
		const char *path);
t_list					*ft_get_folder_rec(char *validarg, char *flags);
t_list					*ft_get_file_rec(char *validarg, char *flags);
t_list					*ft_get_rec_norm(t_list *filelist, char *flags,
		char *validarg, struct dirent *infostruct);
void					ft_rec_parsing(char *flags, t_list *arglist);
int						ft_ls_recursive(char *validarg, char *flags);

#endif
