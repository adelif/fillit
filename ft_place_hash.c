/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_hash.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfelissa <dfelissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 22:32:38 by dfelissa          #+#    #+#             */
/*   Updated: 2019/04/18 18:50:19 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		ft_check_symbol_nb(char *line)
{
	int		i;
	int		p;
	int		d;

	i = 0;
	p = 0;
	d = 0;
	while (line[i])
	{
		if (line[i] == '.')
			p++;
		if (line[i] == '#')
			d++;
		i++;
	}
	if (p == 12 && d == 4)
		return (0);
	return (-1);
}

static int		ft_check_shape(char **tab)
{
	int			i;
	int			j;
	int			s;

	j = 0;
	i = 0;
	s = 0;
	while (j < 4)
	{
		while ((i <= 3) && (tab[j][i]))
		{
			if ((i < 3) && tab[j][i] == '#' && tab[j][i + 1] == '#')
				s++;
			if ((i > 0) && tab[j][i] == '#' && tab[j][i - 1] == '#')
				s++;
			if ((j > 0) && tab[j][i] == '#' && tab[j - 1][i] == '#')
				s++;
			if ((j < 3) && tab[j][i] == '#' && tab[j + 1][i] == '#')
				s++;
			i++;
		}
		i = 0;
		j++;
	}
	if (s == 6 || s == 8)
		return (1);
return (-1);
}

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

int	ft_place_hash(int *save, char **tab)
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	abs;
	char **newtab;

	newtab = malloc(sizeof(char*) * 4);
	j = 0;
	y = 0;
	i = 1;
	while (i < 8 && j < 8)
	{
		/*if (save[j] == 0 && save[i] == 0)
		{
				newtab = tab;
				printf("newtab 0 -> %s\nnewtab 1 ->%s\n%s\n%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);
				return (newtab);
		}*/
	while (i < 8)	
		if (save[i] < save[i +=2])
			y = save[i];
		printf("%d\n", y);
	/*	printf("newtab 0 -> %s\nnewtab 1 ->%s\n%s\n%s\n", newtab[0], newtab[1], newtab[2], newtab[3]);*/
	}
	return (y);
}

int		main()
{
	char **tab;

	tab = malloc(sizeof(char*) * 4);
	tab[0] = "..#.";
	tab[1] = ".###";
	tab[2] = "....";
	tab[3] = "....";
	ft_check_shape(tab);
	printf("%d\n", ft_check_shape(tab));
	ft_save_position(tab);
	ft_place_hash(ft_save_position(tab), tab);
	return (0);
}
