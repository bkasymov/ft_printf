/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:14:17 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 16:14:26 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "apply_spec.h"
#define DEFAULT_FLOAT_PRECISION 6

/*
**  Return string that contains n chars c
**	If n <= 0, return nonzero ptr to empty string
*/

char	*char_n_dup(char c, int n)
{
	char	*res;

	res = 0;
	if (n < 0)
		n = 0;
	if (n + 1 < n)
		return (0);
	res = ft_memalloc(n > 0 ? n + 1 : 1);
	if (!res)
		return (0);
	if (n <= 0)
		return (res);
	while (n--)
		res[n] = c;
	return (res);
}

int	is_signed_conversion(t_spec spec)
{
	if (spec.conv == 'i' || spec.conv == 'f' || spec.conv == 'd')
		return (1);
	return (0);
}

int	is_numeric(t_spec spec)
{
	if (\
		spec.conv == 'd' || spec.conv == 'i' || \
		spec.conv == 'o' || spec.conv == 'u' || \
		spec.conv == 'x' || spec.conv == 'X' || \
		spec.conv == 'f' \
	   )
		return (1);
	return (0);
}

int	is_nonfloat_numeric(t_spec spec)
{
	if (is_numeric(spec) || spec.conv != 'f')
		return (1);
	return (0);
}

/*
**  Modify only the copy of original string
**	Always return a copy. Copy always MUST be freed.
*/

char	*apply_spec(char *s, t_spec *spec)
{
	char	*new;

	if (\
		!(new = ft_strdup(s)) ||\
		!(new = apply_precision(new, *spec)) ||\
		!(new = apply_numeric_flags(new, *spec)) ||\
		!(new = apply_width(new, *spec)) \
		)
	{
		free(s);
		return (0);
	}
	if  (ft_strlen(s) == 0 && spec->conv == 'c')
		spec->stupid_c0_special_case = 1;
	return (new);
}
