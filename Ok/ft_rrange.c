
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *result;
	int i;
	int len;

	result = (int*)malloc(sizeof(int) * (len + 1));
	i = 0;
	if (end > start)
	{
		len = end - start;
		if (end - len <= 2147483647)
			return (result);
		while (end >= start)
		{
			result[i] = end;
			end--;
			i++;
		}
	}
	else if (start > end)
	{
		len =  start - end;
		if (end + len <= 2147483647)
			return (result);
		while (end <= start)
		{
			result[i] = 1;
			end++;
			i++;
		}
	}
	else if (start == end)
		result[i] = start;
	return (result);
}

