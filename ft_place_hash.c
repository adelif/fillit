/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_hash_position.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:32:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/04/16 14:43:03 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_save_position(char **tab)
{
	int	i;
	int	abs;
	int	ord;
	int	*save;

	if (!(save = (int*)malloc(sizeof(int) * 8 + 1)))
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
	return (save);
}

char	**ft_place_hash(int *save, char **tab)
{
	int	i;
	int	j;
	int	x;
	int	ord;
	int	abs;
	char **newtab;

	newtab = malloc(sizeof(char*) * 4);
	i = 0;
	j = 0;
	x = 0;
	while (i < 8)
	{
		if (save[i] == 0 && save[i++] == 0)
		{
				newtab = tab;
				printf("newtab 0 -> %s\nnewtab 1 ->%s\n%s\n%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);
				return (newtab);
		}
		if (save[i] != 0 && tab[ord][abs])
			while (save[i*2] > 0 && i < 4)
			{
				ord--;
				x--;
				printf("x -> %d\n", x);
				newtab[i][j] = tab[ord - (x)][abs];
			}
		i++;
		abs++;
		printf("newtab 0 -> %s\nnewtab 1 ->%s\n%s\n%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);
		return (newtab);
		}
	return (0);
}

int		main()
{
	char **tab;

	tab = malloc(sizeof(char*) * 4);
	tab[0] = "....";
	tab[1] = "....";
	tab[2] = "##..";
	tab[3] = "##..";
	ft_save_position(tab);
	ft_place_hash(ft_save_position(tab), tab);
	return (0);
}
