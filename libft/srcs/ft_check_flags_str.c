/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:29:04 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:32:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_check_if_flags_str(t_flags b, char *str)
{
	if (b.precision != -1 && b.letter == 'S')
		str = ft_size_prec_uni(b, str);
	if (b.precision != -1 && b.letter != 'c' && b.letter != 'C')
		str = ft_size_prec_str(b, str);
	if (b.lenght != 0)
		str = ft_size_lenght_str(b, str);
	return (str);
}
