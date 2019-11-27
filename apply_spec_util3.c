/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec_util3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:00:45 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:00:46 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "apply_spec.h"

int		only_zeros(char *s)
{
	while (*s)
		if (*s++ != '0')
			return (0);
	return (1);
}

char	*apply_hash(char *s, t_spec spec)
{
	if (((spec.conv == 'p')&& ft_strcmp(s, "(nil)")))
		return (add_prefix(s, "0x"));

	if (spec.flag_hash == 1 && spec.precision == 0 && spec.conv == 'o')
		return (add_prefix(s, "0"));
	if (spec.flag_hash != 1 || only_zeros(s))
		return (s);
	if (spec.conv == 'o' && s[0] != '0')
		return (add_prefix(s, "0"));
	if (\
			(spec.conv == 'x' && ft_strcmp(s, "0")) ||\
			((spec.conv == 'p')&& ft_strcmp(s, "(nil)")))
		return (add_prefix(s, "0x"));
	if (spec.conv == 'X' && ft_strcmp(s, "0"))
		return (add_prefix(s, "0X"));
	if (spec.conv == 'f' && !ft_strchr(s, '.'))
		return (add_suffix(s, ".0"));
	return (s);
}

char	*apply_plus(char *s, t_spec spec)
{
	if (spec.flag_plus != 1)
		return (s);
	if (is_signed_conversion(spec) && s[0] != '-')
		return (add_prefix(s, "+")); 
	// Man page says sign should always be + or -. How about 0??
	return (s);
}

char	*apply_space(char *s, t_spec spec)
{
	if (spec.flag_space != 1 || spec.flag_plus == 1)
		return (s);
	if (is_signed_conversion(spec) && s[0] != '-' )
		return (add_prefix(s, " ")); 
	// Man page says prefix should be added only for POSITIVE numbers
	// We reproduce bug and consider 0 as positive number
	return (s);
}

/*
**  "+" " " "#"
*/

char	*apply_numeric_flags(char *s, t_spec spec)
{
	if (spec.conv == 'p')
		return ((s = apply_hash(s, spec)));
	if (is_numeric(spec) &&\
		(s = apply_hash(s, spec)) &&\
		(s = apply_plus(s, spec)) &&\
		(s = apply_space(s, spec))\
	   )
		return (s);
	return (s);
}
