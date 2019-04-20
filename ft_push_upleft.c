/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_upleft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:32:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/04/20 14:24:55 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int		*ft_save_position(char **tab)/* fonction qui sauvegarde les coordonées initiales du tétri*/
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

int		ft_abs_min(int *save) /* fct° qui rechercher la plus petite abscisse*/
{
	int	i;
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
	printf("x  = %d\n", x);
	return (x);
}

int	*ft_push_upleft(int *save, int x) /* fct qui donne les coordonées théorique le + en haut à gauche*/
{
	int	i;
	int	y;

	i = 1;
	while (i <= 7)
	{
			save[i] -= x;
			i += 2;
	}
	i = 0;
	y = 0;
	while (save[i] > 0)
	{
		y++;
		save[i] -= 1;
	}
	i += 2;
	while (i <= 6)
	{
		save[i]	-= y;
		i += 2;
	}
	return (save);
}

char		**ft_replace_hash(int *save, char **tab) /* fct° qui met des hashtag aux coordonées le plus en haut à gauche*/
{
	int	i;
	int	j;
	char	**newtab;
	char	*str;

	str = "....";
	i = 0;
	if (!(newtab=(char**)malloc(sizeof(char *) * 4 + 1)))
		return (NULL);
	while (i < 4)
	{
		newtab[i] = ft_strdup(str);
		i++;
	}
	i = 0;
	j = 1;
	while (i <= 6 && j <= 7)
	{
		newtab[save[i]][save[j]] = '#';
		i += 2;
		j += 2;
	}
	printf("newtab 0 ->%s\nnewtab 1 ->%s\nnewtab 2 ->%s\nnewtab 3 ->%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);
	return (newtab);
}
int			main()
{
	char	**tab;

	tab = malloc(sizeof(char*) * 4);
	tab[0] = "....";
	tab[1] = "..##";
	tab[2] = "...#";
	tab[3] = "...#.";
	ft_replace_hash(ft_push_upleft(ft_save_position(tab), ft_abs_min(ft_save_position(tab))),tab);
	return (0);
}
