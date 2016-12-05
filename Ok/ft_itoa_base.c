#include <stdlib.h>
#include <stdio.h>

int ft_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	aux(int n, int b, char *ans, int *p)
{
	char	base[] = "0123456789ABCDEF";

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	ans[(*p)++] = base[ft_positive(n % b)];
}

char	*ft_itoa_base(int value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 35)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

int		main(int ac, char **argv)
{
	(void)ac;
	printf("%s", ft_itoa_base(atoi(argv[1]), atoi(argv[2])));
	return(0);
}