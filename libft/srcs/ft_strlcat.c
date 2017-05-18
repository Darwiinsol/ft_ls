/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 13:53:52 by apissier          #+#    #+#             */
/*   Updated: 2016/12/02 10:53:25 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src,
			size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = ft_strlen(dst);
	j = ft_strlen(src);
	a = 0;
	if (size == 0)
		return (j);
	while (src[a] && i + a < size - 1)
	{
		dst[a + i] = src[a];
		a++;
	}
	dst[a + i] = '\0';
	if (i < size)
		return (j + i);
	else
		return (j + size);
}
