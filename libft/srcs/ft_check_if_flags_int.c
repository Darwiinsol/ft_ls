/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_flags_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 12:21:20 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:33:08 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_check_if_flags_int(t_flags b, char *str)
{
	size_t		negative;
	char		*tmp;

	negative = 0;
	if (str[0] == '-')
	{
		negative = 1;
		str = ft_strncpy(str, &str[1], ft_strlen(str) - 1);
		str[ft_strlen(str) - 1] = '\0';
	}
	if (b.precision != -1)
		str = ft_size_prec_int(b, str);
	if (negative == 1)
	{
		tmp = str;
		str = ft_strjoin("-", tmp);
		ft_memdel((void **)&tmp);
	}
	if (b.plus == 1)
		str = ft_is_plus(b, str, negative);
	else if (b.blank == 1 && b.plus != 1 && negative != 1)
		str = ft_is_blank(b, str, negative);
	str = ft_join_flags_int(b, str);
	return (str);
}
