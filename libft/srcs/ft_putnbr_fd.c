/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:22:32 by apissier          #+#    #+#             */
/*   Updated: 2016/11/25 16:06:04 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		tmp = tmp * (-1);
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
	else
	{
		n = tmp;
		n = n + '0';
		ft_putchar_fd(n, fd);
	}
}
