#include <stdio.h>
#include <stdlib.h>
#include "printf.h"

int	ft_inter_len(long long inter)
{
	int				i;

	i = 0;
	if (inter <= 0)
	{
		inter = inter * (-1);
		i++;
	}
	while (inter > 0)
	{
		inter = inter / 10;
		i++;
	}
	return (i);
}

char    *ft_ftoa(double num, int p)
{
    struct varftoa f;

    f.inter = (long long)num;
    f.tmp = (double)f.inter;
    f.fraction = num - f.tmp;
    f.len_till_dot = ft_inter_len(f.inter);
    if (p == 0)
    {
        if (!(f.str = (char *)malloc(sizeof(char) * f.len_till_dot + 1)))
            return (NULL);
        while (0 <= f.len_till_dot)
		{
			f.str[f.len_till_dot--] = f.inter % 10 + '0';
			f.inter /= 10;
		}
	}
}