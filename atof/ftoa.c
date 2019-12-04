
#include "ft_fp.h"
#include "t_float.h"

void	fill_t_float(long double x, t_float *num)
{
    num->mant = *((unsigned long int *)&x); 
	num->exp = *(unsigned short *)((char *)&x + sizeof(unsigned long int));
	num->sign = num->exp & (((unsigned short) 1) << 15);
	num->exp = num->exp & ((~((unsigned short) 0)) >> 1);
	num->mant_mask = (((unsigned long int) 1) << 63);
	num->mask_shift = 0;
}

static int	abs(int x)
{
	return (x >= 0 ? x : -x);
}

char	*eval_power_sum(t_float *num, int power_of2)
{
	static char	res[LD_MAX_DIGITS];
	t_decimal	total;
	t_decimal	current;
	t_decimal	accum;

	positive_ascii_to(&accum, "0");
	positive_ascii_to(&total, power_of2 > 0 ? "2" : "0.5");
	power_positive_decimal(&total, abs(power_of2));
	while (num->mask_shift < 64)
	{
		if (num->mant_mask >> num->mask_shift & num->mant)
		{
			positive_ascii_to(&current, "0.5");
			power_positive_decimal(&current, num->mask_shift);
			multiply_positive_decimal(&current, &total);
			add_positive_decimal(&accum, &current);
		}
		num->mask_shift++;
	}
	if (num->sign)
		accum.is_negative = 1;
	to_ascii(accum, res);
	return (res);
}

char	*normal_case(t_float *num)
{
	return (eval_power_sum(num, num->exp - 16383));
}

char	*exp_all_zeros(t_float *num)
{
	if (!num->mant)
		return (num->sign ? "-0.0" : "0.0");
	return (eval_power_sum(num, -16382));
}

char	*exp_all_ones(t_float *num)
{
	//62-0 bits of mant ==0 
	if (!(num->mant & ~num->mant_mask))	
		return (num->sign ? "-inf" : "inf");
	return ("NaN");
}

char	*ftoa(long double x)
{
	t_float	num;

	fill_t_float(x, &num);
	if (!~((num.exp << 1) + 1))
		return (exp_all_ones(&num));
	else if (!(num.exp << 1))
		return (exp_all_zeros(&num));
	else
		return (normal_case(&num));
}
