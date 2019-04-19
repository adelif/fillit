#include "./libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

char		**ft_transform_hash(char **tab)
{
	int		i;
	int		j;
	int		nb;
	char	**str;

	i = 0;
	j = 0;
	nb = 15;
	if (!(str = (char**)malloc(sizeof(char*) * 4 + 1)))
		return (0);
	while (j < 4)
	{
		while ((i <= 3))
		{
			if (i = 3)
				str[j] = tab[j + 2];
			while (tab[j][i] == '.' && nb<= 26)
                                i++;

		}
		i = 0;
		j++;
	}
	str[2] = "....";
	str[3] = "....";
	/*str[j] = tab[2];
	str[j + 1] = tab[3];
	nb++;*/
	printf("str 0 -> %s\nstr 1 ->%s\n%s\n%s\n", str[0], str[1], str[2], str[3]);
	return (str);
}

int	main(int ac, char **av)
{
	char	**tab;

	if (!(tab = (char**)malloc(sizeof(char*) * 4 + 1)))
		return (5);
	tab[0] = (ft_strdup("...."));
	tab[1] = (ft_strdup("...."));
	tab[2] = (ft_strdup("##.."));
	tab[3] = (ft_strdup("##.."));
	printf("%s\n%s\n%s\n%s\n\n", tab[0], tab[1], tab[2], tab[3]);
	ft_transform_hash(tab);
	return (0);
}
