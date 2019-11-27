/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:03:18 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:03:20 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Fill all fields of structure with zeros.
*/

void		init_spec(t_spec *spec)
{
	spec->flag_zero = 0;
	spec->flag_hash = 0;
	spec->flag_plus = 0;
	spec->flag_dash = 0;
	spec->flag_space = 0;
	spec->width = 0;
	spec->precision = -1;
	spec->length = 0;
	spec->conv = 0;
	spec->stupid_c0_special_case = 0;
}

void		read_flag(const char c, t_spec *spec)
{
	if (c == '+')
		spec->flag_plus = 1;
	if (c == '-')
		spec->flag_dash = 1;
	if (c == ' ')
		spec->flag_space = 1;
	if (c == '#')
		spec->flag_hash = 1;
	if (c == '0')
		spec->flag_zero = 1;
}

/*
**	Read any nonnegative number of flags.
**	One flag can be mentioned more than once
**  No other chars expected here.
**	Return a pointer to first non-flag char in f
*/

const char	*read_flags(const char *f, t_spec *spec)
{
	while (*f == '+' || *f == '-' || *f == ' ' || *f == '#' || *f == '0')
		read_flag(*(f++), spec);
	return (f);
}

/*
**	Read all arguments of conversion spceification
**	Return 
**	-pointer to first char after the end of conversion specification
**	-0 in case of any problems (abscence of conversion specifier)
**	Side effects: change a spec
*/

const char	*read_spec(const char *format, t_spec *spec)
{
	init_spec(spec);
	format = read_flags(format, spec);
	format = read_width(format, spec);
	if (*format == '.')
	{
		//Copy of original UB (No precision spec provided but point exists)
		//Initialize with zero instead of negative number in this case
		spec->precision = 0;
		format = read_precision(++format, spec);
	}
	format = read_length(format, spec);
	format = read_conv_spec(format, spec); 
	return (format);
}
