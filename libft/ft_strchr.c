/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:30:14 by apissier          #+#    #+#             */
/*   Updated: 2016/11/25 14:30:36 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	int		i;
	char	*t;

	t = (char*)s;
	i = 0;
	while (t[i] != c && t[i])
		i++;
	if (t[i] == c)
		return (&t[i]);
	return (NULL);
}
