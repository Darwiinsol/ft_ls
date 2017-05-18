/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:03:39 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:34:47 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

intmax_t		ft_length_modifier_signed(va_list ap, t_flags b)
{
	intmax_t	i;

	if (b.l == 1 || b.letter == 'D')
		i = (intmax_t)va_arg(ap, long);
	else if (b.h == 2)
		i = (intmax_t)(char)va_arg(ap, int);
	else if (b.h == 1)
		i = (intmax_t)(short)va_arg(ap, int);
	else if (b.l == 2)
		i = (intmax_t)va_arg(ap, long long);
	else if (b.j == 1)
		i = va_arg(ap, intmax_t);
	else if (b.z == 1)
		i = (intmax_t)va_arg(ap, ssize_t);
	else
		i = (intmax_t)va_arg(ap, int);
	return (i);
}

uintmax_t		ft_lenght_modifier_unsigned(va_list ap, t_flags b)
{
	uintmax_t	i;

	i = 0;
	if (b.l == 1 || b.letter == 'U' || b.letter == 'O')
		i = (uintmax_t)va_arg(ap, unsigned long);
	else if (b.h == 2)
		i = (uintmax_t)(unsigned char)va_arg(ap, unsigned int);
	else if (b.h == 1)
		i = (uintmax_t)(unsigned short)va_arg(ap, unsigned int);
	else if (b.l == 1 || b.letter == 'U' || b.letter == 'O')
		i = (uintmax_t)va_arg(ap, unsigned long);
	else if (b.l == 2)
		i = (uintmax_t)va_arg(ap, unsigned long long);
	else if (b.j == 1)
		i = va_arg(ap, uintmax_t);
	else if (b.z == 1)
		i = (uintmax_t)va_arg(ap, size_t);
	else
		i = (uintmax_t)va_arg(ap, unsigned int);
	return (i);
}
