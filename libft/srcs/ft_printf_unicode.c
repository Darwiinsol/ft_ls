/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 15:58:16 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:36:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** 127 = 01111111
** 2047 = 0000011111111111 / 192 = 11000000 128 = 10000000 63 = 111111
** 65535 = 1111111111111111 / 224 = 11100000
** 1114111 = 100001111111111111111 / 240 = 11110000
*/

static char		*ft_unicode_3o(wchar_t wc, char *str)
{
	str = ft_strnew(3);
	str[0] = ((wc >> 12) + 224);
	str[1] = (((wc >> 6) & 63) + 128);
	str[2] = ((wc & 63) + 128);
	return (str);
}

static char		*ft_unicode_4o(wchar_t wc, char *str)
{
	str = ft_strnew(4);
	str[0] = ((wc >> 18) + 240);
	str[1] = (((wc >> 12) & 63) + 128);
	str[2] = (((wc >> 6) & 63) + 128);
	str[3] = ((wc & 63) + 128);
	return (str);
}

char			*ft_unicode(wchar_t wc)
{
	char		*str;

	str = NULL;
	if (wc <= 127)
	{
		str = ft_strnew(1);
		str[0] = wc;
	}
	else if (wc <= 2047)
	{
		str = ft_strnew(2);
		str[0] = ((wc >> 6) + 192);
		str[1] = ((wc & 63) + 128);
	}
	else if (wc <= 65535)
		str = ft_unicode_3o(wc, str);
	else if (wc <= 1114111)
		str = ft_unicode_4o(wc, str);
	return (str);
}
