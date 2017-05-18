/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:14:47 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:37:04 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*ft_itoa_uintmax_t(uintmax_t n)
{
	int				i;
	char			*str;
	uintmax_t		tmp;

	i = 2;
	tmp = n;
	while ((tmp = tmp / 10) != 0)
		i++;
	if ((str = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	str[--i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int					ft_printf_unsigned(va_list ap, t_flags b, char i)
{
	uintmax_t		u;
	char			*str;
	int				len;

	b.letter = i;
	u = ft_lenght_modifier_unsigned(ap, b);
	if (u == 0 && b.precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_uintmax_t(u);
	str = ft_check_if_flags_int(b, str);
	len = ft_free_return(&str);
	return (len);
}
