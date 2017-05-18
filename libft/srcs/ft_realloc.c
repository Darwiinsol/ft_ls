/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 13:50:28 by apissier          #+#    #+#             */
/*   Updated: 2016/12/09 10:51:03 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t cur_size, size_t new_size)
{
	void	*new;
	size_t	i;

	if (new_size <= cur_size)
		return (ptr);
	if (!(new = ft_memalloc(new_size)))
		return (NULL);
	i = 0;
	while (i < cur_size)
	{
		((char*)new)[i] = ((char*)ptr)[i];
		i++;
	}
	free(ptr);
	return (new);
}
