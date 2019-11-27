/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:03:30 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:03:31 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Skip all digits if they exist in format spec.
**  Fill the field "width"
**	Return: ptr to first non-digit in f
*/

const char	*read_width(const char *f, t_spec *spec)
{
	if (ft_isdigit(*f))
		spec->width = ft_atoi(f);
	while (ft_isdigit(*f))
		f++;
	return (f);
}

/*
**	Skip all digits if they exist in format spec.
**  Fill the field "precision"
**	Return: ptr to first non-digit in f
*/

const char	*read_precision(const char *f, t_spec *spec)
{
	if (ft_isdigit(*f))
		spec->precision = ft_atoi(f);
	while (ft_isdigit(*f))
		f++;
	return (f);
}

/*
**	Skip all digits if they exist in format spec.
**  Fill the field "length"
**	Return: ptr to first non-length specifier in f
**	UPD: peers say, that we must process multiple length specifiers 
**	and select max of them. Enum is ordered actually.
*/

const char	*read_length(const char *f, t_spec *spec)
{
	while (*f == 'l' || *f == 'L' || *f == 'h')
	{
		if (*f == 'l' && *(f + 1) == 'l' && spec->length < ll)
			spec->length = ll;
		if (*f == 'l' && *(f + 1) != 'l' && spec->length < l)
			spec->length = l;
		if (*f == 'h' && *(f + 1) == 'h' && spec->length < hh)
			spec->length = hh;
		if (*f == 'h' && *(f + 1) != 'h' && spec->length < h)
			spec->length = h;
		if (*f == 'L' && spec->length < L)
			spec->length = L;
		f++;
	}
	return (f);
}

const char	*read_conv_spec(const char *f, t_spec *spec)
{
	if (\
			*f != 'd' &&*f != 'i' && *f != 'o' && *f != 'u' && *f != 'x'\
			&& *f !='X' && *f != 'f' && *f != 'c' && *f != 's'	&& *f != 'p'\
			&& *f != '%'\
		)
		return (0);
	spec->conv = *f;
	return (++f);
}
