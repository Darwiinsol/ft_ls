/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:40:58 by apissier          #+#    #+#             */
/*   Updated: 2017/04/10 17:58:46 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*dest;
	int		count;
	int		i;
	char	*s2;

	i = 0;
	count = 0;
	s2 = (char *)s;
	while (s2[count])
		count++;
	if (!(dest = (char *)malloc(sizeof(*s2) * (count + 1))))
		return (0);
	while (s2[i])
	{
		dest[i] = s2[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
