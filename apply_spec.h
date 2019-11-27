#ifndef APPLY_SPEC_H
# define APPLY_SPEC_H

#define DEFAULT_FLOAT_PRECISION 6


/*
** On apply_spec.c
*/

char	*apply_spec(char *s, t_spec *spec);
char	*char_n_dup(char c, int n);
int		is_signed_conversion(t_spec spec);
int		is_numeric(t_spec spec);
int		is_nonfloat_numeric(t_spec spec);

/*
** Continue in apply_spec_util.c
*/

char	*float_precision(char *s, t_spec spec);
char	*apply_precision(char *s, t_spec spec);
char	*apply_fzero(char *s, t_spec spec);
char	*apply_fdash(char *s, t_spec spec);
char	*apply_width(char *s, t_spec spec);


/*
** On apply_spec_util2.c
*/
char	*str_replace(char *s, char pattern, char replacement);
char	*add_suffix(char *s, char *suffix);
char	*add_prefix(char *s, char *prefix);
char	*prepend_zeros(char *s, int n);
char	*str_insert(char *dst, char *src, int pos);

/*
** On apply_spec_util3.c
*/

int		only_zeros(char *s);
char	*apply_hash(char *s, t_spec spec);
char	*apply_plus(char *s, t_spec spec);
char	*apply_space(char *s, t_spec spec);
char	*apply_numeric_flags(char *s, t_spec spec);

/*
** On apply_spec_util4.c
*/

int		len_after_dot(char *s);
char	*round_float(char *s, int precision);

#endif
