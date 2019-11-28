/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wrappers_int2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 11:34:06 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/28 11:34:06 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*w_itoa_b8(void *n)
{
	return (itoa_b8(*(long long *)n));
}

char	*w_itoa_X(void *n)
{
	return (itoa_bX(*(long long *)n));
}

char	*w_itoa_x(void *n)
{
	return (itoa_bx(*(long long *)n));
}
