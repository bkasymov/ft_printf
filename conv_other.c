
/*
**	Here you can find declarations of non-integer conversion functions
*/

#include "printf.h"

/*
**   Char to string
*/

char	*ctoa(char c)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (1 + 1));
	if (!res)
		return (res);
	res[0] = c;
	res[1] = 0;
	return (res);
}

/*
** ID function =)
*/

char	*stoa(char *s)
{
	return (s);
}

/*
** Rerurn string representation of void ptr as hex 
*/

char	*ptoa(void *p)
{
	return (itoa_bx(*(int *)p));
}

char	*percent_to_a()
{
	return (ft_strdup("%"));
}
