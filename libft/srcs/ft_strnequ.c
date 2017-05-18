/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:10:57 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 17:46:02 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*t1;
	char	*t2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	t1 = (char*)s1;
	t2 = (char*)s2;
	i = 0;
	while (i < n && (t2[i] || t1[i]))
	{
		if (t1[i] != t2[i])
			return (0);
		i++;
	}
	return (1);
}
