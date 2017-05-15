/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:40:49 by apissier          #+#    #+#             */
/*   Updated: 2017/04/10 17:54:20 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*srce;

	i = 0;
	dest = (char*)dst;
	srce = (char*)src;
	while (i < n)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dest);
}
