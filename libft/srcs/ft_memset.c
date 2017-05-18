/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:08:28 by apissier          #+#    #+#             */
/*   Updated: 2016/11/25 17:21:26 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char*)s;
	while (i < n)
	{
		s1[i] = c;
		i++;
	}
	return (s1);
}