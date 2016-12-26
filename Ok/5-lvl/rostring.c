#include <stdlib.h>
#include <unistd.h>

int 	count_word(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{

		if (str[i] >= 33 && str[i] <= 126 &&
							(str[i + 1] == '\0' ||
								(str[i + 1] < 33 || str[i + 1] > 126)))
			j++;
		i++;
	}
	return (j);
}
void 	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
char *is_blank(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == '\r')
		i++;
	return (&str[i]);
}

int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *cut_word(char *str)
{
	int i;
	char *word;

	i = 0;
	if ((word = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
		return (NULL);
	while (str[i] != '\0' && str[i] >= 33 && str[i] <= 126)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char 	*epur_str(char *str)
{
	int i;
	int j;
	char *dst;

	i = 0;
	j = 0;
	str = is_blank(str);
	dst = str;
	while (str[i] != '\0')
	{
		if (str[i] >= 33 && str[i] <= 126)
		{
			dst[j] = str[i];
			j++;
		}
		else if ((str[i] == '\n' || str[i] == '\t' || str[i] == '\v' || str[i] == ' ' || str[i] == '\r') && (str[i + 1] != '\0' && str[i + 1] >= 33 &&  str[i+1] <= 126))
		{
			dst[j] = ' ';
			j++;
		}
		i++;
	}
	dst[j] = '\0';	
	return (dst);
}

char *rostring(char *str)
{
	char *word;
	int 	i;
	int 	j;
	int 	nbr_word;

	 if ((word = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))) == NULL)
	 	return (str);
	i = 0;
	j = 0;
	str = epur_str(str);
	nbr_word = count_word(str);
	if (ft_strlen(str) != 0 && nbr_word > 1)
	{
		word = cut_word(str);
		i = ft_strlen(word) + 1;
		str = &str[i];
		i = ft_strlen(str);
		str[i++] = ' ';
		j = 0;
		while (word[j] != '\0')
		{
			str[i] = word[j];
			i++;
			j++;
		}
		str[i] = '\0';
	}
	return (str);
}


int main(int ac, char **av)
{
	if (ac == 2)
	{
		av[1] = rostring(av[1]);
		ft_putstr(av[1]);	
	}
	write (1, "\n", 1);
}