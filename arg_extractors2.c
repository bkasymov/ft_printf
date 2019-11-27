/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_extractors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:10:12 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 18:10:13 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "fp_type.h"

/*
**	Choose integer extractor depending on signed/unsigned
*/

i_extr_fun	choose_i_extr(t_spec spec)
{
	return (is_usgn(spec) ? &extr_uint : &extr_sint);
}

/*
**	If we understand rules of C language correctly, :-) this conversions 
**  do not lead to data corruption.
**	Now we may have UB (signed overflow).
*/

void	*int_extractor(t_spec spec, va_list *vl)
{
	long long	*p;

	if ((p = ft_memalloc(sizeof(long long))))
		return (choose_i_extr(spec)(spec, vl, p));
	return ((void *)p);
}

void	*float_extractor(t_spec spec, va_list *vl)
{
	long double	*p;
	
	if ((p = ft_memalloc(sizeof(long double))))
	{
		if (spec.length == ll || spec.length == l || spec.length == L)
			*p += va_arg(*vl, long double);
		else
			*p += va_arg(*vl, double);
	}
	return ((void *)p);
}

void	*char_extractor(t_spec spec, va_list *vl)
{
	char	*p;
	
	(void)spec;
	if ((p = ft_memalloc(sizeof(char) * 2)))
	{
		p[0] = va_arg(*vl, int);
		p[1] = 0;
	}
	return ((void *)p);
}
