/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 18:34:35 by apissier          #+#    #+#             */
/*   Updated: 2017/05/18 11:32:15 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_flags				ft_check_flags(char i, t_flags b)
{
	if (i == '#' || i == '0' || i == '-' || i == '+' || i == ' ')
	{
		if (i == '#')
			b.sharp = 1;
		if (i == '0')
			b.zero = 1;
		if (i == '-')
			b.minus = 1;
		if (i == '+')
			b.plus = 1;
		if (i == ' ')
			b.blank = 1;
		return (b);
	}
	return (b);
}

int					ft_flags(char i)
{
	if (i == '#' || i == '0' || i == '-' || i == '+' || i == ' ')
		return (1);
	return (0);
}

int					ft_modifier(char i)
{
	if (i == 'h' || i == 'l' || i == 'z' || i == 'j')
		return (1);
	return (0);
}

t_flags				ft_check_modifier(char i, char j, t_flags b)
{
	if (i == 'h' || i == 'l' || i == 'z' || i == 'j')
	{
		if (i == 'h')
		{
			if (j == 'h')
				b.h++;
			b.h++;
		}
		if (i == 'l')
		{
			if (j == 'l')
				b.l++;
			b.l++;
		}
		if (i == 'z')
			b.z = 1;
		if (i == 'j')
			b.j = 1;
		return (b);
	}
	return (b);
}
