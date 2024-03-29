/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:33:11 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 14:35:19 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_sort_ascii(char *a, char *b)
{
	if (a && b)
	{
		if ((ft_strcmp(a, b)) > 0)
			return (0);
	}
	return (1);
}
