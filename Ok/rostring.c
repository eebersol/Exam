#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count_word(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] != '\0')
			return (3);
		i++;
	}
	return (0);
}

int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char 	*cut_space(char *str)
{
	int i;
	int j;
	char *s1;

	i = 0;
	j = 0;
	s1 = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\n') {
			str[i] = ' ';
		}
		if ((str[i] >= 33 && str[i] <= 126) || (str[i + 1] && str[i] == ' ' && str[i + 1] != ' ')) {;
				s1[j] = str[i];
			j++;
		}
		i++;
	}
	return (s1);
}

char 	*rostring(char *str)
{
	char *s1;
	char *first_word;
	int i;
	int j;
	int k;

	k = 0;
	i = 0;
	j = 0;
	s1 = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	first_word = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r' || str[i] == '\n')
		i++;
	s1 = &str[i];
	s1 = cut_space(s1);
	i = 0;
	if (count_word(s1) != 0)
		{
		while (s1[j] != ' ')
		{
			first_word[i] = s1[j];
			j++;
			i++;
		}
		j++;
		s1 = &s1[j];
		i = ft_strlen(s1);
		j = 0;
		s1[i] = ' ';
		i++;
		while (k < ft_strlen(first_word)) {
			s1[i] = first_word[j];
			j++;
			i++;
			k++;
		}
		s1[i] = '\0';
		return (s1);
	} else {
		s1[ft_strlen(s1)] = '\0';
		return (s1);
	}
}

int main(int ac, char **av)
{
	char *str;

	if (ac == 2)
	{
		str = (char*)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		str = rostring(av[1]);
		write (1, str, ft_strlen(str));
		write(1, "\n", 1);

	}
	else {

		printf("ici\n");
		write(1, "\n", 1);
	}
} 