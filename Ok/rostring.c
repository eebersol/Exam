#import <unistd.h>
#import <stdlib.h>
#import <stdio.h>


int 	ft_strlen(char *str)
{
	int i;

	i =0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char 	*skip_useless_space(char *str)
{
	int i;
	int j;
	char *dst;

	i = 0;
	j = 0;
	dst = (char*)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] && str[i - 1] >= 33 && str[i - 1] <= 126))
		{
			dst[j] = str[i];
			j++;
		}
		i++;

	}
	dst[j] = '\0';
	return (dst);
}

char 	*rostring(char *str)
{
	char *dst;
	int i;
	int j;

	dst = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = -1;
	j = 0;
	while (str[++i] != ' ' && str[i] != '\0')
		dst[i] = str[i];
	dst[i++] = '\0';
	str = &str[i];
	if (ft_strlen(str) == 0)
		return (dst);
	i = 0;
	while (str[i] != '\0')
		i++;
	str[i++] = ' ';
	while (dst[j] != '\0')
	{
		str[i + j] = dst[j];
		j++;
	}
	free(dst);
	return (str);
}

int 	main(int ac, char **av)
{
	char *result;

	if (ac >= 2)
	{
		result = (char*)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
		result = skip_useless_space(av[1]);
		result = rostring(result);
		write(1, result, (ft_strlen(result)));
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);


}