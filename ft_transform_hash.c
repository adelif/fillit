#include	<stdlib.h>
#include	<stdio.h>

char	**ft_transform_hash(char **tab)
{
	int	i;
	int	j;
	int	s;
	int	nb;

	i = 0;
	j = 0;
	s = 0;
	nb = 1;

	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	while (j < 4)
	{
		while (i < 4)
		{
			if (tab[j][i] == 35 && nb <= 26)
			{
				tab[j][i] =  35 + 29 + nb;
				// printf("%d\n", i);
			}
			i++;
		}
		j++;
	}
	nb++;
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	return(tab);
}

int main(int ac, char **av)
{
	char	**tab;

	if (!(tab =(char**)malloc(sizeof(char*) * 4 + 1)))
		return (5);
	tab[0] = ".#..";
	tab[1] = "###.";
	tab[2] = "....";
	tab[3] = "....";
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	ft_transform_hash(tab);
	return (0);
}