/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:08:22 by apissier          #+#    #+#             */
/*   Updated: 2017/09/25 18:12:05 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int         ft_intlen(long long nbr)
{
    int     len;

    len = 0;
    if (nbr == 0)
        return (1);
    if (nbr < 0)
        return (-1);
    while (nbr > 0)
    {
        len++;
        nbr = nbr / 10;
    }
    return (len);
}