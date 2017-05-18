/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_prec_uni.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 16:50:42 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:38:07 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_check_nb_octet(char str)
{
	if ((str & 128) == 0)
		return (1);
	if ((str & 224) == 192)
		return (2);
	if ((str & 240) == 224)
		return (3);
	if ((str & 248) == 240)
		return (4);
	return (0);
}

char		*ft_size_prec_uni(t_flags b, char *str)
{
	int		nb_octet;
	int		i;

	nb_octet = 0;
	i = 0;
	while (i + nb_octet <= b.precision)
	{
		i += nb_octet;
		nb_octet = ft_check_nb_octet(str[i]);
	}
	str[i] = '\0';
	return (str);
}
