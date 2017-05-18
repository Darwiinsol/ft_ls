/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 18:05:04 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:32:34 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			ft_apply_width(t_flags b, char i)
{
	char			*str;
	int				len;

	str = ft_strchar(i, 1);
	str = ft_check_if_flags_str(b, str);
	if (b.precision == 0)
		str[ft_strlen(str) - 1] = i;
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int					ft_check_letter(va_list ap, char i, t_flags b)
{
	if (i == 'd' || i == 'D' || i == 'i')
		return (ft_printf_di(ap, i, b));
	else if (i == '%')
		return (ft_printf_percent(b));
	else if (i == 's' || i == 'S')
		return (ft_printf_string(ap, b, i));
	else if (i == 'c' || i == 'C')
		return (ft_printf_char(ap, b, i));
	else if (i == 'x' || i == 'X')
		return (ft_printf_hexa(ap, b, i));
	else if (i == 'o' || i == 'O')
		return (ft_printf_octal(ap, b, i));
	else if (i == 'u' || i == 'U')
		return (ft_printf_unsigned(ap, b, i));
	else if (i == 'p')
		return (ft_printf_pointer(ap, b));
	else if (ft_isprint(i))
		return (ft_apply_width(b, i));
	return (0);
}
