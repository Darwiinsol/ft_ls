/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:38:59 by apissier          #+#    #+#             */
/*   Updated: 2016/11/30 17:43:25 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
		return (NULL);
	ft_memset(tmp, 0, size);
	return (tmp);
}
