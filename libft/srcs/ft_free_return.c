/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_return.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:34:14 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:33:22 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_free_return(char **str)
{
	int		len;

	len = 0;
	if (str == NULL)
		return (0);
	ft_putstr(*str);
	len = ft_strlen(*str);
	free(*str);
	return (len);
}
