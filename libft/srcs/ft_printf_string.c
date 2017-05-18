/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:13:34 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:36:36 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*ft_string_unicode(char *uni, wchar_t *str)
{
	char			*tmp;
	char			*tmp2;

	uni = ft_strdup("");
	while (*str)
	{
		if (!(tmp = ft_unicode(*str)))
			return (0);
		tmp2 = uni;
		uni = ft_strjoin(tmp2, tmp);
		free(tmp);
		free(tmp2);
		str++;
	}
	return (uni);
}

static int			ft_printf_smaj(va_list ap, t_flags b)
{
	wchar_t	*str;
	char	*uni;
	int		len;

	b.letter = 'S';
	uni = NULL;
	str = va_arg(ap, wchar_t *);
	if (str == NULL)
		uni = ft_strdup("(null)");
	else
		uni = ft_string_unicode(uni, str);
	uni = ft_check_if_flags_str(b, uni);
	len = ft_free_return(&uni);
	return (len);
}

int					ft_printf_string(va_list ap, t_flags b, char i)
{
	int				len;
	char			*str;

	if (b.l == 1 || i == 'S')
		len = ft_printf_smaj(ap, b);
	else
	{
		b.letter = 's';
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			str = ft_strdup("(null)");
			str = ft_check_if_flags_str(b, str);
			len = ft_free_return(&str);
		}
		else
		{
			str = ft_check_if_flags_str(b, str);
			ft_putstr(str);
			len = ft_strlen(str);
			str = NULL;
		}
	}
	return (len);
}
