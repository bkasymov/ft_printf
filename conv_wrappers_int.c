/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_wrappers_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:02:07 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:02:09 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*w_itoa_b10u(void *n)
{
	return (itoa_b10u(*(long long *)n));
}

char	*w_itoa_b10(void *n)
{
	return (itoa_b10(*(long long *)n));
}

char	*w_itoa_b2(void *n)
{
	return (itoa_b2(*(long long *)n));
}
