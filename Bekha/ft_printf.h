#ifndef PRINTF_H
#define PRINTF_H

#include "libft.h"
#include <stdarg.h>

int     ft_printf(const char *format, ...);

enum length {none, hh, h, l, ll, L};

typedef struct ft_printf    s_spec
{
    int     flag_zero;
    int     flag_hash;
    int     flag_plus;
    int     flag_dash;
    int     flag_space;

    int     width;
    int     precision;
    enum    length;

    char    conv;
    int     strupid_c0_special_case;
}           t_spec;

/*
**  Для чего помещать функции в структуру отдельную?
*/

typedef struct s_conv_f
{
    char    *specifiers; // все спецификаторы
    void    *(*arg_extract_)(t_spec spec, va_list *vl); //вытаскивает аргумент
    char    *(*to_str)(void *arg); //превращает аргумент в строку
    int     cleanup_needed;//
};          t_conv_f;

char    *itoa_b10u(long long n);
char    *itoa_b10(long long n);
char    *itoa_b2(long long n);
char    *itoa_b8(long long n);
char    *itoa_bX(long long n);
char    *itoa_bx(long long n);

// обёртка для того, чтобы принимать любую переменную

char	*w_itoa_b10u(void *n);
char	*w_itoa_b10(void *n);
char	*w_itoa_b2(void *n);
char	*w_itoa_b8(void *n);
char	*w_itoa_X(void *n);
char	*w_itoa_x(void *n);

char     *ftoa(long double x);
char     *ctoa(char c);
char     *stoa(char *s);
char      *ptoa(void *p);
char     *percent_to_a();

char	*w_ftoa(void *x);
char	*w_ctoa(void *x);
char	*w_stoa(void *x);
char	*w_ptoa(void *x);
char	*w_percent(void *x);

void    *int_extractor(t_spec spec, va_list *vl);
void    *float_extractor(t_spec spec, va_list *vl);
void    *char_extractor(t_spec spec, va_list *vl);
void    *dummy_extractor(t_spec spec, va_list *vl);

# define ACTIONS {\
    {"di", &w_itoa_b10, &int_extractor, 1},\
    {"u", &w_itoa_b10u, &int_extractor, 1},\
    {"o", &w_itoa_b8, &int_extractor, 1},\
    {"xp", &w_itoa_x, &int_extractor, 1},\
    {"X", &w_itoa_X, &int_extractor, 1},\
    {"f", &w_ftoa, &float_extractor, 1},\
    {"c", &w_ctoa, &char_extractor, 1},\
    {"s", &w_stoa, &str_extractor, 0},\
    {"%", &w_percent, &dummy_extractor, 0},\
    {"b", &w_binary, &binary_extractor, 1},\
    {0, 0, 0, 0}\
}

struct varftoa
{
    long double     fraction;
    long long       inter;
    long double     tmp;
    char            *str;
    int             lenbef;
    int             i;
    int             lenaf;
};

t_conv_f        *find_action(t_spec spec);

#endif