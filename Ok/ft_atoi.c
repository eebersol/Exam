/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int 	ft_atoi(char *pStr)
{
	int		n;
	char	g;

	n = 0;
	if (*pStr == '-')
	{
		g = 1;
		pStr++;
	}
	while (*pStr >= '0' && *pStr <= '9') 
	{
		n *= 10;
		n += *pStr - '0';
		pStr++;
	}
	if (g) 
		n *= -1;
	return (n);
}

int 	main(int argc, char **argv) 
{
	int i;

	i = 0;
	if (argc == 2) 
	{
		i = ft_atoi(argv[1]);
		ft_putnbr(i);
	}
	else
		return (1);
	return (0);
}