/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_hash_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:32:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/04/15 22:47:49 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_save_position(char **tab)
{
	int	i;
	int	abs;
	int	ord;
	int	*save;

	if(!(save=(int*)malloc(sizeof(int) * 8 + 1)))
		return (NULL);
	i = 0;
	abs = 0;
	ord = 0;
	while (ord < 4)
	{
		if (tab[ord][abs] == '#')
		{
			printf("ord = %d abs = %d\n", ord, abs); 
			save[i++] = ord;
			save[i++] = abs;
		}
		if (abs >= 4)
		{
			abs = -1;
			ord++;
		}
		abs++;
	}
}



int		main()
{
	char **tab;

	tab = malloc(sizeof(char*) * 4);
	tab[0] = "##..";
        tab[1] = "##..";
        tab[2] = "....";
        tab[3] = "....";
	ft_save_position(tab);
	return (0);
}
