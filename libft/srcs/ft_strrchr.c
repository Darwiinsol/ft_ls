/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:41:20 by apissier          #+#    #+#             */
/*   Updated: 2016/11/24 21:12:19 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*t;

	t = (char*)s;
	i = 0;
	j = 0;
	while (t[i])
		i++;
	while (t[i] != c && i)
		i--;
	if (t[i] == c)
		return (&t[i]);
	return (NULL);
}
