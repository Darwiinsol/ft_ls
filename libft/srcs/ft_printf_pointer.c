/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:13:01 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:36:17 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char			*ft_pointer_to_hex(unsigned long u)
{
	char			*str;
	unsigned long	tmp;
	int				cnt;

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

int					ft_printf_pointer(va_list ap, t_flags b)
{
	unsigned long	u;
	int				len;
	char			*str;

	len = 0;
	b.letter = 'p';
	u = (unsigned long)va_arg(ap, void *);
	if (u == 0 && b.precision > -1)
		str = ft_strdup("");
	else
		str = ft_pointer_to_hex(u);
	if (str == NULL)
		return (0);
	str = ft_check_if_flags_int(b, str);
	len = ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}
