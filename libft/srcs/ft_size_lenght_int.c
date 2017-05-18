/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_lenght_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:16:30 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:37:20 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_size_lenght_int(t_flags b, char *str)
{
	char	*tmp;

	if (b.lenght == 0)
		return (str);
	else if (b.lenght <= (int)ft_strlen(str))
		return (str);
	else
	{
		tmp = (char *)malloc(b.lenght - ft_strlen(str) + 1);
		if (b.zero == 1 && b.minus != 1 && b.precision == -1)
			tmp = ft_memset(tmp, '0', b.lenght - ft_strlen(str));
		else
			tmp = ft_memset(tmp, ' ', b.lenght - ft_strlen(str));
		tmp[b.lenght - ft_strlen(str)] = '\0';
		str = ft_join_lenght_int(b, tmp, str);
		free(tmp);
	}
	return (str);
}
