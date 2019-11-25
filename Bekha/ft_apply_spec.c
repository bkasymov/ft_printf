char    *apply_width(char *s, t_spec spec)
{
    
}

/*
В функции применения сначала берется копия строки
в переменную new и дальше идёт применение необходимых
свойств, которые дал пользователь;
Сначала точность, далее числовые флаги и ширина.
*/

char    *apply_spec(char *s, t_spec *spec)
{
    char    *new;

    if (!(new = ft_strdup(s)) ||\
        !(new = apply_precision(new, *spec)) ||\
        !(new = apply_numeric_flags(new, *spec)) ||\
        !(new = apply_width(new, *spec)))
            return (0);
    if (ft_strlen(s) == 0 && spec->conv = 'c')
        spec->stupid_c0_special_case = 1;
}