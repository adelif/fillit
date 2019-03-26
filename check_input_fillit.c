/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_fillit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:20:40 by alebui            #+#    #+#             */
/*   Updated: 2019/03/26 10:57:21 by dfelissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int			hashkey_nb_check(int fd, char *line)
{
	int		hash_nb;
	int		i;

	hash_nb = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			hash_nb++;
			i++;
		}
		else if (line[i] == '.')
			i++;
		else
			return (-1);
	}
	return (hash_nb);
}

void		clean_tab(char **tab)
{
	int i;

	i = 0;
	while (i < 4)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

/*
t_tetri		*create_tetri(char **tab, t_tetri **lst, int t_nb)
{
	t_tetri	*piece;
	t_tetri *tmp;
	int i;
	int j;

	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (*lst)
		tmp->next = piece;
	else
		*lst = piece;
	if (!(piece = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(piece->shape = (char **)malloc(sizeof(char *) * 4)))
		return (NULL);
	i = 0;
	while (i < 4)
	{
		piece->shape[i] = ft_strdup(tab[i]);
		//printf("piece->shape[%d] = %s\n", i, piece->shape[i]);
		// remplacer les dieses par des lettres
		i++;
	}
	piece->order = t_nb;
	piece->next = NULL;
	return (piece);
}
*/

int		ft_check_shape(char **tab)
{
	int	d[3];

	d[0] = 0;//i
	d[1] = 0;//j
	d[2] = 0;//s
	while (d[1] < 4)
	{
		while ((d[0] <= 3) && (tab[d[1]][d[0]]))
		{
			if ((d[0] < 3) && tab[d[1]][d[0]] == '#' && tab[d[1]][d[0] + 1] == '#')
				d[2]++;
			if ((d[0] > 0) && tab[d[1]][d[0]] == '#' && tab[d[1]][d[0] - 1] == '#')
				d[2]++;
			if ((d[1] > 0) && tab[d[1]][d[0]] == '#' && tab[d[1] - 1][d[0]] == '#')
				d[2]++;
			if ((d[1] < 3) && tab[d[1]][d[0]] == '#' && tab[d[1] + 1][d[0]] == '#')
				d[2]++;
			d[0]++;
		}
		d[0] = 0;
		d[1]++;
	}
	if (d[2] == 6 || d[2] == 8)
		return (1);
	return (-1);
}

int			check_file(int fd, char *line, char **tab)
{
	int 	ret_gnl;
	int		is_tetri;
	int		t_nb;
	int		l_nb;
	int		hash_nb;
	int		hash_tot;
	int		i;
	t_tetri	*piece;

	t_nb = 1;
	l_nb = 1;
	hash_nb = 0;
	hash_tot = 0;
	is_tetri = 1;
	i = 0;
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{
		if (ft_strlen(line) != 4 && ft_strlen(line) != 0)
			return (-1);
		if ((hash_nb = hashkey_nb_check(fd, line)) == -1)
			return (-1);
		if (l_nb == 5 && ft_strlen(line) != 0)
			return (-1);
		if (ft_strlen(line) == 0)
		{
			if (l_nb != 5)
				return (-1);
			if (hash_tot != 4)
				return (-1);
			t_nb++;
			l_nb = 0;
			hash_tot = 0;
			/* Si le check de la forme est ok, creer un maillon */
			if (ft_check_shape(tab) == 1)
			{
				// Appeler fonction pour creer un maillon;
				printf("Je creer un maillon\n");
			}
			else
			{
				// Appeler fonction pour supprimer toute la liste chainer et retourner une erreur;
				printf("DEL LISTE\n");
			}
			i = 0;
		}
		if (t_nb > 26)
			return (-1);
		/* Je copie chaque line dans tab[i] */
		if (ft_strlen(line) != 0)
		{
			tab[i] = ft_strcpy(tab[i], line);
			printf("tab[%d] : %s ; Tetri nb : %d\n", i, tab[i], t_nb);
			i++;
		}
		hash_tot += hash_nb;
		l_nb++;
	}
	return (0);
}

int			is_valid(int fd, char *line)
{
	char 	**tab;
	t_tetri	*piece;
	int 	file;
	int 	i;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (-1);
	i = 0;
	while (i < 4)
	{
		tab[i] = ft_strnew(4);
		i++;
	}
	if (!(file = check_file(fd, line, tab)))
		printf("coucou\n");
	else
		printf("ERROR\n");
	clean_tab(tab);
	return (0);
}

int		main(int ac, char **av)
{
	int fd;
	char *line;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		is_valid(fd, line);
	}
	return (0);
}
