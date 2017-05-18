/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:03:35 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:35:38 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		*ft_int_to_hexa(uintmax_t u)
{
	char		*str;
	uintmax_t	tmp;
	int			cnt;

	tmp = u;
	cnt = 2;
	while ((tmp = tmp / 16) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		if (u % 16 < 10)
			str[cnt] = (u % 16 + 48);
		if (u % 16 >= 10)
			str[cnt] = (u % 16 + 87);
		u = u / 16;
	}
	return (str);
}

static char		*ft_int_to_hexa_maj(uintmax_t u)
{
	char		*str;
	uintmax_t	tmp;
	int			cnt;

	tmp = u;
	cnt = 2;
	while ((tmp = tmp / 16) != 0)
		cnt++;
	if ((str = (char *)malloc(sizeof(char) * cnt)) == NULL)
		return (0);
	str[--cnt] = '\0';
	while (cnt-- > 0)
	{
		if (u % 16 < 10)
			str[cnt] = (u % 16 + 48);
		if (u % 16 >= 10)
			str[cnt] = (u % 16 + 55);
		u = u / 16;
	}
	return (str);
}

static char		*ft_zero(char *str, t_flags b)
{
	str = ft_strdup("");
	str = ft_size_lenght_int(b, str);
	return (str);
}

int				ft_printf_hexa(va_list ap, t_flags b, char i)
{
	uintmax_t	u;
	char		*str;
	int			len;

	str = NULL;
	u = ft_lenght_modifier_unsigned(ap, b);
	if (b.precision == 0 && u == 0)
		str = ft_zero(str, b);
	else if (u == 0)
		str = ft_strdup("0");
	else if (i == 'x')
	{
		b.letter = 'x';
		str = ft_int_to_hexa(u);
	}
	else if (i == 'X')
	{
		b.letter = 'X';
		str = ft_int_to_hexa_maj(u);
	}
	str = ft_check_if_flags_int(b, str);
	len = ft_free_return(&str);
	return (len);
}
