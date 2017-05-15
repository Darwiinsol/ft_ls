/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:17:48 by apissier          #+#    #+#             */
/*   Updated: 2016/12/02 12:49:24 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\f' ||
		c == '\r' || c == '\t')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *nptr)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	neg = 0;
	nb = 0;
	while (isspace(nptr[i]) == 1)
		i++;
	if (nptr[i] == '-')
		neg = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] <= 47 || nptr[i] >= 58)
		return (0);
	while (nptr[i] <= 57 && nptr[i] >= 48 && nptr[i])
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	if (neg == 1)
		return (-nb);
	return (nb);
}
