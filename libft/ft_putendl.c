/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 12:56:35 by apissier          #+#    #+#             */
/*   Updated: 2016/11/25 12:59:58 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putendl(char const *s)
{
	int		i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		ft_putchar(s[i++]);
	ft_putchar('\n');
}
