#include <stdlib.h>

char	*ft_itoa_base(int n, int base)
{
	char 	base_digits[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int 	converted_number[64];
	int 	i = 0;
	int 	value;
	char 	*result;

	value = n;
	if (n < 0)
		n = n * -1;
	while (n != 0)
	{
		converted_number[i] = n % base;
		n = n / base;
		i++;
	}
	i--;
	result = (char*)malloc(sizeof(char) * i);
	if (value < 0)
	{
		result[0] = '-';
		value = 1;
	}
	while (i >= 0)
	{
		result[value] = base_digits[converted_number[i]];
		i--;
		n++;
	}
	return (result);
}
