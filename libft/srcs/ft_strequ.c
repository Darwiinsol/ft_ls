/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:01:24 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 16:10:20 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	char	*t1;
	char	*t2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	t1 = (char*)s1;
	t2 = (char*)s2;
	i = 0;
	while (t1[i] && t2[i] && t1[i] == t2[i])
		i++;
	if (t1[i] == '\0' && t2[i] == '\0')
		return (1);
	else
		return (0);
}
