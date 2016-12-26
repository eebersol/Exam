#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		ft_atoi(const char *str)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (str[i] == '-')
		return (0);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		nbr = nbr * 10;
		nbr = nbr + (str[i] - 48);
		i++;
	}
	return (nbr);
}


void	ft_putnbr(int nbr)
{
	char c;

	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
}

int		ft_is_prim(int nbr)
{
	int i;

	i = 2;
	while (i < nbr)
	{
		if (nbr % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(int nbr)
{
	int i;
	int count;

	i = 2;
	count = 0;
	while (i <= nbr)
	{
		if (ft_is_prim(i))
			count = count + i;
		i++;
	}
	ft_putnbr(count);
}


int 	main(int ac, char **av)
{
	if (ac == 2)
		add_prime_sum(ft_atoi(av[1]));
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}