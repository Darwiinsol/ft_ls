/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_flags_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:43:29 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:34:18 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_join_flags_int(t_flags b, char *str)
{
	if ((b.sharp == 1 && b.letter == 'x') || b.letter == 'p')
		str = ft_strjoinffree("0x", str);
	if (b.sharp == 1 && b.letter == 'X')
		str = ft_strjoinffree("0X", str);
	if (b.lenght != 0)
		str = ft_size_lenght_int(b, str);
	return (str);
}
