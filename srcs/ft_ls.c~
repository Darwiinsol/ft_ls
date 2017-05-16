/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apissier <apissier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 18:00:32 by apissier          #+#    #+#             */
/*   Updated: 2017/05/15 16:57:49 by apissier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include "../libft/libft.h"

int				main(int ac, char **av)
{
	DIR* rep = NULL;
	struct dirent* fichierlu = NULL;
	struct stat *buff = NULL;
	rep = opendir(av[1]);
	if (rep == NULL)
	{
		perror("Erreur");
		return(0);
	}
	else
		printf("Le fichier a ete ouvert correctement");
	while((fichierlu = readdir(rep)) != NULL)
		printf("\nLe fichier lu s'appel '%s'", fichierlu->d_name);
	if (closedir(rep) == -1)
	{
		perror("Erreur");
		return(0);
	}
	else
		printf("\nLe Fichier a ete ferme correctement");
	return (0);
}
