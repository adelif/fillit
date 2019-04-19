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

int main(int ac, char **av)
{
	char	**tab;

	tab = malloc(sizeof(char*) * 4);
        tab[0] = "...#";
        tab[1] = "...#";
        tab[2] = "...#";
        tab[3] = "...#";
	printf("%d",ft_check_shape(tab));
	return (0);

}
