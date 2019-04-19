#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

char		**ft_push_up(char **tab)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			if (tab[j][i] == '.')
				i++;
		}
		if (i == 3)
			str[j + 2] = ft_strdup(tab[j]);
		i = 0;
		j++;
	}
	str[j + 1] = tab[j + 3];
	str[j + 2] = tab[j];
	str[j + 3] = tab[j + 1];
	while (i < 4)
	{
		printf("str[%d] : %s\n", i, str[i]);
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	char	**tab;

	if (!(	tab = (char**)malloc(sizeof(char*) * 4 + 1)))
		return (5);
	tab[0] = (ft_strdup("...."));
	tab[1] = (ft_strdup("...."));
	tab[2] = (ft_strdup("..##"));
	tab[3] = (ft_strdup("..##"));
	printf("%s\n%s\n%s\n%s\n", tab[0], tab[1], tab[2], tab[3]);
	ft_push_up(tab);
	return (0);
}
