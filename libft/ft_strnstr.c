/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:35:40 by apissier          #+#    #+#             */
/*   Updated: 2016/12/02 11:40:39 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *a, const char *b, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big;
	char	*little;

	i = 0;
	j = 0;
	big = (char *)a;
	little = (char *)b;
	if (little[j] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && big[i + j] && i + j < len)
				j++;
			if (little[j] == '\0')
				return (&big[i]);
		}
		i++;
	}
	return (NULL);
}
