/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:36:39 by apissier          #+#    #+#             */
/*   Updated: 2017/04/26 17:09:27 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinfree(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		c;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	c = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[c])
		new[i++] = s2[c++];
	new[i] = '\0';
	free(s1);
	free(s2);
	return (new);
}
