/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 17:16:00 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 16:33:10 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_LS
# define FT_LS
# include <stdlib.h>
# include <dirent.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

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
}						t_ls;	

t_list					*ft_sort_by_ascii(t_list *liste);
t_list					*ft_check_sort(t_list *liste, t_flag b);

#endif