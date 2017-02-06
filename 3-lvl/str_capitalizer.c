#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int 	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
char    *strcapitalize_strlowcase(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
        str[i] += 32;
      i++;
    }
  return str;
}

char	* str_capitalizer(char *str)
{
  int	i;
  int	flag;

	i = 0;
	flag = 1;
	strcapitalize_strlowcase(str);
	while (str[i] != '\0')
    {
		if (str[i] > 96 && str[i] < 123)
		{
			if (flag == 1 && ((str[i - 1] == ' ') || i == 0))
			{
				str[i] -= 32;
			}
			flag = 0;
		}
		else if (str[i] > 47 && str[i] < 58)
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return str;
}

int 	main(int ac, char **av)
{
	int i;

	i = 1;
	if (ac >= 2)
	{
		while (i < ac)
		{
			write(1, str_capitalizer(av[i]), ft_strlen(av[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);

}