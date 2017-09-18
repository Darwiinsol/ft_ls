/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinmulti.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 10:02:24 by apissier          #+#    #+#             */
/*   Updated: 2017/09/17 10:52:21 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char            *ft_strjoinmulti(char const *s1, char const *s2, char const *s3, char const *s4)
{
    int         i;
    int         j;
    char        *rslt;

    i = -1;
    j = ((ft_strlen(s1)) + (ft_strlen(s2)) + (ft_strlen(s3)) + (ft_strlen(s4)));

    if (!(rslt = (char*)malloc(sizeof(char) * (j + 1))))
        return (NULL);

    while (*s1 != '\0')
        rslt[++i] = *s1++;
    while (*s2 != '\0')
        rslt[++i] = *s2++;
    while (*s3 != '\0')
        rslt[++i] = *s3++;
    while (*s4 != '\0')
        rslt[++i] = *s4++;
    rslt[++i] = '\0';
    return (rslt);
}