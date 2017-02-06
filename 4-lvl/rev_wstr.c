


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char 	*is_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (&str[i]);
}
char 	*cut_word(char *str)
{
	int i;
	char *word;

	str = is_blank(str);
	i = 0;
	if ((word = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)) == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] >= 33 && str[i] <= 126)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);

}
int 	count_word(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126 && (str[i+1] == '\0' || str[i + 1] < 33 || str[i+1] > 126))
			j++;
		i++;
	}
	return (j);
}

char **split(char *str)
{
	int i;
	int nbr_word;
	char **tab;
	char *word;

	nbr_word = count_word(str);
	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * nbr_word + 1)) == NULL)
		return (NULL);
	while (i < nbr_word)
	{
		word = cut_word(str);
		tab[i] = (char*)malloc(sizeof(char) * ft_strlen(word));
		tab[i] = word;
		str = &str[ft_strlen(word) + 1];
		i++;
	}
	tab[i] = "\0";
	return (tab);
}

int main(int ac, char **av)
{
	char **tab;
	int i;

	i = 0;
	if (ac == 2)
	{
		tab = split(av[1]);
		i = count_word(av[1]);
		while (i >= 0)
		{
			ft_putstr(tab[i]);
			if (i < count_word(av[1]) && i > 0)
				write(1, " ", 1);
			i--;
		}
	}
	write(1, "\n", 1);
}