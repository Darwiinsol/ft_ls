/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:57:53 by apissier          #+#    #+#             */
/*   Updated: 2016/11/24 21:38:45 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *mdf, const char *a)
{
	char	*dest;
	char	*src;
	int		i;
	int		j;

	i = 0;
	src = (char*)a;
	dest = (char*)mdf;
	if (src[0] == '\0')
		return (dest);
	while (dest[i])
	{
		j = 0;
		if (dest[i] == src[j])
		{
			while (dest[j] && dest[i + j] == src[j])
			{
				j++;
				if (src[j] == '\0')
					return (&dest[i]);
			}
		}
		i++;
	}
	return (NULL);
}
