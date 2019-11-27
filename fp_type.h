/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_type.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:02:36 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:02:38 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FP_TYPE_H
# define FP_TYPE_H

# include "printf.h"

typedef	void	*(*i_extr_fun)(t_spec, va_list *, long long *);
void			*char_extractor(t_spec spec, va_list *vl);
void			*float_extractor(t_spec spec, va_list *vl);
void			*int_extractor(t_spec spec, va_list *vl);
i_extr_fun		choose_i_extr(t_spec spec);
int				is_usgn(t_spec spec);
void			*extr_sint(t_spec spec, va_list *vl, long long *p);
void			*extr_uint(t_spec spec, va_list *vl, long long *p);
void			*str_extractor(t_spec spec, va_list *vl);
t_conv_f		*find_action(t_spec spec);
void	*dummy_extractor(t_spec spec, va_list *vl);


#endif

