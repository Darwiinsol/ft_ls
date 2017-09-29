/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:21:55 by apissier          #+#    #+#             */
/*   Updated: 2017/09/28 20:07:33 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void			ft_get_flags(char *flags, char *format)
{
	int				flags_count;

	flags_count = ft_strlen(flags);
	while (*format)
	{
		if (ft_strchr(LS_FLAGS, *format))
		{
			if (!ft_strchr(flags, *format))
				flags[flags_count++] = *format;
			format++;
		}
		else
			ft_get_error(1, format);
	}
}
