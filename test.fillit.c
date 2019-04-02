#include <stdio.h>
#include <stdlib.h>

//
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
//

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

int main(int ac, char **av)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 4 + 1)))
				return (5);
	tab[0] = ".#..";
	tab[1] = "###.";
	tab[2] = "....";
	tab[3] = "....";
	ft_check_shape(tab);
	printf("%d", ft_check_shape(tab));
	return (0);
}

