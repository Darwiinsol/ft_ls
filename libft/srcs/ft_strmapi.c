/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:53:38 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 16:00:16 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	char			*s1;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new == NULL)
		return (NULL);
	s1 = (char*)s;
	while (s1[i])
	{
		new[i] = (*f)(i, s1[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
