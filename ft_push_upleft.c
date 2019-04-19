/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:32:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/04/19 16:56:51 by dfelissa         ###   ########.fr       */
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

	i = 0;
	abs = 0;
	ord = 0;
	if (!(save = (int*)malloc(sizeof(int) * 8 + 1)))
		return (NULL);
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

int		ft_abs_min(int *save)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	x = save[i];
	while (i < 6)
	{
		if (x >= save[i += 2])
			x = save[i];
		else
			x = x;
	}
	printf("%d\n", x);
	return (x);
}

int	*ft_push_upleft(int *save, int x)
{
	int	i;
	int	*newabs;

	i = 1;
	if (!(newabs = (int*)malloc(sizeof(int) * 8 + 1)))
		return (NULL);
	while (save[i] && i <= 5)
	{
		newabs[i] = save[i] - x;
	}
	i += 2;
/*	printf("nw 1 ->%d\nnw2 ->%d\n%d\n%d\n", newabs[1], newabs[3], newabs[5], newabs[7]);*/
	return (newabs);
}

/*	while (i < 8 && j < 8)
{
	if (save[j] == 0 && save[i] == 0)
	{
		newtab = tab;
		printf("newtab 0 -> %s\nnewtab 1 ->%s\n%s\n%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);
		return (newtab);
	}
}*/

int			main()
{
	char	**tab;

	tab = malloc(sizeof(char*) * 4);
	tab[0] = "....";
	tab[1] = "##..";
	tab[2] = ".#..";
	tab[3] = ".#..";
	ft_save_position(tab);
	ft_abs_min(ft_save_position(tab));
	ft_push_upleft(ft_save_position(tab), ft_abs_min(ft_save_position(tab)));
	return (0);
}
