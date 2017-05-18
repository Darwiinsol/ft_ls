/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:52:28 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:35:13 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			ft_printf_c_unicode(va_list ap, t_flags b)
{
	wchar_t			c;
	char			*str;
	int				len;
	int				i;

	str = NULL;
	i = 0;
	b.letter = 'C';
	c = va_arg(ap, wchar_t);
	if (c == 0)
	{
		if (b.lenght >= 2)
		{
			while (i++ < b.lenght - 1)
				ft_putchar(' ');
			b.lenght--;
		}
		ft_write_null();
		return (b.lenght + 1);
	}
	str = ft_unicode(c);
	str = ft_check_if_flags_str(b, str);
	len = ft_free_return(&str);
	return (len);
}

void				ft_lenght_c(t_flags *b, char **str)
{
	*str = ft_strchar(' ', b->lenght - 1);
	if (b->zero == 1)
		*str = ft_strchar('0', b->lenght - 1);
	b->lenght--;
	ft_putstr(*str);
}

int					ft_printf_char(va_list ap, t_flags b, char i)
{
	int				len;
	char			c;
	char			*str;

	if (b.l == 1 || i == 'C')
		len = ft_printf_c_unicode(ap, b);
	else
	{
		b.letter = 'c';
		i = '\0';
		c = (char)va_arg(ap, int);
		if (c == 0)
		{
			if (b.lenght >= 2)
				ft_lenght_c(&b, &str);
			return (b.lenght + 1);
		}
		str = ft_strchar(c, 1);
		str = ft_check_if_flags_str(b, str);
		len = ft_free_return(&str);
	}
	return (len);
}
