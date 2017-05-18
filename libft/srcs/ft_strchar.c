/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:20:42 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:39:02 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchar(char c, size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(str, c, size);
	str[size] = '\0';
	return (str);
}
