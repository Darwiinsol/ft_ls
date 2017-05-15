/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:41:51 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 15:52:13 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	char	*s1;
	int		i;

	if (s == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new == NULL)
		return (NULL);
	s1 = (char*)s;
	i = 0;
	while (s1[i])
	{
		new[i] = (*f)(s1[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
