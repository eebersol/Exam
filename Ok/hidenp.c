#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int 	check_substring(char *s1, char *s2)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = ft_strlen(s2);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[j])
		{
			j++;
		}
		i++;
	}
		
	if (j == k)
		return (1);
	else 
		return (0);
}

int 	main(int ac, char **av)
{
	if (ac >= 3)
	{
		if (check_substring(av[2], av[1]) == 1)
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);
	}
	else
		write(1, "\n", 1);
}