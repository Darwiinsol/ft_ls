/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:07:14 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:35:25 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void			n_isnegative(intmax_t *n, int *is_negative)
{
	if (*n < 0)
	{
		*is_negative = 1;
		*n = *n * -1;
	}
}

static char			*ft_itoa_intmax_t(intmax_t n)
{
	int				i;
	char			*str;
	int				is_negative;
	intmax_t		tmp;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = 2;
	is_negative = 0;
	tmp = n;
	n_isnegative(&n, &is_negative);
	while ((tmp = tmp / 10) != 0)
		i++;
	i = i + is_negative;
	if ((str = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	str[--i] = '\0';
	while (i-- > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (is_negative == 1)
		str[0] = '-';
	return (str);
}

/*
**  intmax_t c pour gérer D qui est signed
*/

int					ft_printf_di(va_list ap, char i, t_flags b)
{
	intmax_t		c;
	char			*str;
	int				len;

	if (i == 'd')
		b.letter = 'i';
	else
		b.letter = i;
	c = ft_length_modifier_signed(ap, b);
	if (c == 0 && b.precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_intmax_t(c);
	if (str == NULL)
		return (0);
	str = ft_check_if_flags_int(b, str);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_memdel((void **)&str);
	return (len);
}
