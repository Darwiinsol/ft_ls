/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:10:03 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:35:48 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_convert_octal(char *str, uintmax_t u, t_flags b)
{
	uintmax_t	tmp;
	int			cnt;

	cnt = 2;
	tmp = u;
	while ((tmp = tmp / 8) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		str[cnt] = u % 8 + '0';
		u = u / 8;
	}
	if (str[0] == '-')
		str = ft_strdup(&str[1]);
	if (b.sharp == 1)
		str = ft_strjoin("0", str);
	return (str);
}

int				ft_printf_octal(va_list ap, t_flags b, char i)
{
	char		*str;
	uintmax_t	u;
	int			len;

	b.letter = i;
	str = NULL;
	u = ft_lenght_modifier_unsigned(ap, b);
	if ((b.sharp == 1 && u == 0) || (u == 0 && b.lenght == 0 \
		&& b.precision == -1))
		str = ft_strdup("0");
	else if (b.precision == 0 && u == 0)
	{
		str = ft_strdup("");
		str = ft_size_lenght_int(b, str);
	}
	else
		str = ft_convert_octal(str, u, b);
	str = ft_check_if_flags_int(b, str);
	len = ft_free_return(&str);
	return (len);
}
