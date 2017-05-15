/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:36:39 by apissier          #+#    #+#             */
/*   Updated: 2017/03/24 18:32:45 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		c;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
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
	return (new);
}
