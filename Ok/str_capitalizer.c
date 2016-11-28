#include <unistd.h>

char *stringtolowercase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

int main(int ac, char **av)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 1;
	if (ac >= 2)
	{
		while (j < ac) 
		{
			i = 0;
			str = stringtolowercase(av[j]);
			while (str[i] != '\0')
			{
				if ((str[i] >= 'a' && str[i] <= 'z') 
					&& ((str[i - 1] == ' ' 
						&& (str[i + 1] >= 'a' && str[i + 1] <= 'z')) || i == 0))
					str[i] -= 32;
				i++;
			}
			write(1, str, i );
			write(1, "\n", 1);
			j++;
		}
	}
	else
		write(1, "\n", 1);
		
}