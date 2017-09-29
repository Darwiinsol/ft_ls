/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 10:00:31 by apissier          #+#    #+#             */
/*   Updated: 2017/09/17 10:52:41 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t          ft_strcspn(const char *s1, char s2)
{
    int         i;

    i = 0;
    if (s1 && s2)
    {
        while (s1[i] != '\0' && s2 != '\0' && s1[i] != s2)
            i++;
    }
    return (i);
}