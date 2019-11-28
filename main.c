/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:19:41 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/28 13:31:14 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

// Проверка утечки памяти через вывод всех переменных;

int main(void)
{
	int		a = 12345;
	long int	b = 123456789;
	long long 	c = 12345678912345;
	char		d = 'c';
	char		e[] = {"NORMALNO OBRABOTAY MENYA, \
					BISTREE!\nNU ZHE! \nDOLGO!"};
	float		f = 12.345678;
	double		g = 12.345678912345;
	long double h = 0.8765089426;

//	printf("\n%d, %ld, %lld, %c, %s, %f, %f, %Lf\n", a, b, c, d, e, f, g, h);
	ft_printf("SEX PEX\n\n\n%d, %ld, %lld, %c, %s, %f, %f, %Lf\n", a, b, c, d, e, f, g, h);
	return (0);
}
