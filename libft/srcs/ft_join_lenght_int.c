/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_lenght_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:43:57 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:34:32 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_join_lenght_int(t_flags b, char *tmp, char *str)
{
	char *tmp2;

	if (b.minus == 1)
	{
		tmp2 = str;
		str = ft_strjoin(tmp2, tmp);
		free(tmp2);
	}
	else
	{
		tmp2 = str;
		if (b.zero != 1 && b.letter != 'x' && b.letter != 'X')
			str = ft_strjoin(tmp, tmp2);
		else
			str = ftf_join_flags(tmp2, b, tmp);
		free(tmp2);
	}
	return (str);
}
