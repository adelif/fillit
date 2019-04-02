#include "./libft/libft.h"
#include	<stdlib.h>
#include	<stdio.h>

char	**ft_transform_hash(char **tab)
{
	int	i;
	int	j;
	int	s;
	int	nb;
	char	**str;

	i = 0;
	j = 0;
	s = 0;
	nb = 26;

	if (!(str =(char**)malloc(sizeof(char*) * 4 + 1)))
		return (0);
	while ((j < 4) && tab[j][i])
	{
		while ((i <= 3) && (tab[j][i]))
		{
			if (tab[j][i] == 35 && nb <= 26)
				tab[j][i] =  35 + 29 + nb;
			i++;
		}
		i = 0;
		j++;
	}
	nb++;
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	return(str);
}

int main(int ac, char **av)
{
	char	**tab;

	if (!(tab =(char**)malloc(sizeof(char*) * 4 + 1)))
		return (5);
	tab[0] = (ft_strdup("..#."));
	tab[1] = (ft_strdup("..#."));
	tab[2] = (ft_strdup("..#."));
	tab[3] = (ft_strdup("..#."));
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	ft_transform_hash(tab);
	return (0);
}
