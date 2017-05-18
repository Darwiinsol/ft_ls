/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 10:48:17 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:31:29 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_flags				ft_get_precision(const char *format, int *i, t_flags b)
{
	*i = *i + 1;
	if (ft_isdigit(format[*i + 1]))
	{
		b.precision = ft_atoi(&format[*i + 1]);
		while (ft_isdigit(format[*i + 1]))
			*i = *i + 1;
	}
	else
		b.precision = 0;
	return (b);
}

t_flags				ft_getflag(const char *format, int *i, t_flags b)
{
	while (ft_flags(format[*i + 1]))
	{
		b = ft_check_flags(format[*i + 1], b);
		*i = *i + 1;
	}
	if (ft_isdigit(format[*i + 1]))
	{
		b.lenght = ft_atoi(&format[*i + 1]);
		while (ft_isdigit(format[*i + 1]))
			*i = *i + 1;
	}
	if (format[*i + 1] == '.')
		b = ft_get_precision(format, i, b);
	if (ft_modifier(format[*i + 1]))
	{
		b = ft_check_modifier(format[*i + 1], format[*i + 2], b);
		*i += ((b.h == 2 || b.l == 2) ? 2 : 1);
	}
	return (b);
}

int					ft_printf(const char *format, ...)
{
	va_list		ap;
	t_flags		b;
	int			i;
	int			len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		b = (t_flags){0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		if (format[i] == '%')
		{
			b = ft_getflag(format, &i, b);
			len = len + ft_check_letter(ap, format[i + 1], b);
			ft_isprint(format[i + 1]) ? i = i + 2 : i++;
		}
		else
		{
			ft_putchar(format[i++]);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
