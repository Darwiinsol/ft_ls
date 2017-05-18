/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:03:02 by apissier          #+#    #+#             */
/*   Updated: 2016/11/25 15:16:51 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long	tmp;

	tmp = n;
	if (n < 0)
	{
		ft_putchar('-');
		tmp = tmp * (-1);
	}
	if (tmp >= 10)
	{
		ft_putnbr(tmp / 10);
		ft_putnbr(tmp % 10);
	}
	else
	{
		n = tmp;
		n = n + '0';
		ft_putchar(n);
	}
}
