#include <unistd.h>

void 	ft_putnbr(int nbr)
{
	int n;
	char c;

	n = 0;
	c = 0;
	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	if (nbr <= 9) {
		c = nbr;
		c += '0';
		write (1, &c, 1);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr/10);
		ft_putnbr(nbr%10);
	}
}

int 	ft_atoi(char *str)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *=10;
		n += str[i] - '0';
		i++;
	}
	return (n);
}

int 	main(int ac, char **av)
{
	int j;
	int i;

	i = 1;
	j = 0;
	if (ac == 2)
	{
		j = ft_atoi(av[1]);
		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(j);
			write(1, " = ", 3);
			ft_putnbr((i * j));
			write(1, "\n", 1);
			i++;
		}
	} else
		write(1, "\n", 1);
}