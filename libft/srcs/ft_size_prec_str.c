/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_prec_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:19:59 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:37:55 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_size_prec_str(t_flags b, char *str)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (b.precision + 1))))
		return (NULL);
	tmp = ft_memcpy(tmp, str, b.precision);
	tmp[b.precision] = '\0';
	str = ft_strdup(tmp);
	free(tmp);
	return (str);
}
