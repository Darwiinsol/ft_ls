/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:20:14 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 16:35:14 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	char	*new;
	size_t	i;

	if (s == NULL)
		return (0);
	new = (char*)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	s1 = (char*)s;
	i = 0;
	while (i < len && s1[i])
	{
		new[i] = s1[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
