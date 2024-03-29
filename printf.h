/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:55:09 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/29 14:55:10 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define A {{"di", &w_itoa_b10, &int_extractor, 1},
# define B	{"u", &w_itoa_b10u, &int_extractor, 1},
# define C	{"o", &w_itoa_b8, &int_extractor, 1},
# define D	{"xp", &w_itoa_x, &int_extractor, 1},
# define E	{"X", &w_itoa_xx, &int_extractor, 1},
# define F	{"f", &w_ftoa, &float_extractor, 1},
# define G	{"c", &w_ctoa, &char_extractor, 1},
# define H	{"s", &w_stoa, &str_extractor, 0},
# define I	{"%", &w_percent, &dummy_extractor, 0},
# define J	{0, 0, 0, 0}}

# define ACTIONS A B C D E F G H I J

enum				e_length
{
	none,
	hh,
	h,
	l,
	ll,
	L
};

/*
**	Structure that stores our internal representation of "user request"
*/

typedef struct		s_spec
{
	int				flag_zero;
	int				flag_hash;
	int				flag_plus;
	int				flag_dash;
	int				flag_space;

	int				width;
	int				precision;
	enum e_length	length;

	char			conv;
	int				stupid_c0_special_case;
}					t_spec;

typedef struct		s_variablesforfloat
{
	char			*string;
	long long		integer;
	long double		fractional;
	long long		cp_integer;
	long double		cp_fractional;
	int				sym;
	long double		tmp;
	long long		lenbef;
	long long		lenaf;
	long long		cp_lenbef;
	long long		cp_lenaf;
	int				i;
	int				tmp2;
	int				number;
	int				p;
	char			*res;
}					t_varfloat;

/*
**	Generalized conversion function
**	Generalized argument extractor function
**  And all of its specifiers
*/

typedef struct		s_conv_f
{
	char			*specifiers;
	char			*(*to_str)(void *arg);
	void			*(*arg_extract)(t_spec spec, va_list *vl);
	int				cleanup_needed;
}					t_conv_f;

/*
**	Integer convertors
**  TODO: replace stubs with normal functions
*/

char				*itoa_b10u(long long n);
char				*itoa_b10(long long n);
char				*itoa_b2(long long n);

char				*itoa_b8(long long n);
char				*itoa_bxx(long long n);
char				*itoa_bx(long long n);

/*
**	Integer convertors wrappers
*/

char				*w_itoa_b10u(void *n);
char				*w_itoa_b10(void *n);
char				*w_itoa_b2(void *n);

char				*w_itoa_b8(void *n);
char				*w_itoa_xx(void *n);
char				*w_itoa_x(void *n);

/*
**	Non-integer convertors
**  TODO: replace stubs with normal functions
*/

int					ft_inter_len(long long inter);
char				*ftoa(long double x);
char				*ctoa(char c);
char				*stoa(char *s);
char				*ptoa(void *p);
char				*percent_to_a();

/*
**	Non-integer convertors wrappers
*/

char				*w_ftoa(void *x);
char				*w_ctoa(void *x);
char				*w_stoa(void *x);
char				*w_ptoa(void *x);
char				*w_percent(void *x);

/*
**	Argument extractors
*/

void				*int_extractor(t_spec spec, va_list *vl);
void				*float_extractor(t_spec spec, va_list *vl);
void				*char_extractor(t_spec spec, va_list *vl);
void				*str_extractor(t_spec spec, va_list *vl);
void				*dummy_extractor(t_spec spec, va_list *vl);

struct				s_varftoa
{
	long double		fraction;
	long long		inter;
	long double		tmp;
	char			*str;
	int				len_till_dot;
	int				i;
	int				len_af_dot;
};

t_conv_f			*find_action(t_spec spec);

int					ft_printf(const char *format, ...);

#endif
