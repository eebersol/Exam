/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebersol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 20:39:58 by eebersol          #+#    #+#             */
/*   Updated: 2016/05/04 20:39:59 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int			ft_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int			ft_sign_int(int nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

int			ft_len_int(int nbr)
{
	int nbr_len;

	if (nbr == 0)
		return (1);
	nbr_len = 0;
	while (nbr != 0)
	{
		nbr_len++;
		nbr = nbr / 10;
	}
	return (nbr_len);
}

char		*ft_itoa(int n)
{
	int		nbr_len;
	int		value;
	char	*result;

	value = ft_sign_int(n);
	nbr_len = ft_len_int(n);
	result = NULL;
	result = (char*)malloc(sizeof(char) * (nbr_len + value + 1));
	if (result)
	{
		result = result + nbr_len + value;
		*result = '\0';
		if (!n)
			*--result = '0';
		while (n != 0)
		{
			*--result = ft_positive(n % 10) + '0';
			n = n / 10;
		}
		if (value)
			*--result = '-';
	}
	return (result);
}
