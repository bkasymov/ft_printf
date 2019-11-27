/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_spec_util2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpenney <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:00:37 by dpenney           #+#    #+#             */
/*   Updated: 2019/11/27 17:00:41 by dpenney          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "apply_spec.h"

/* return initial string */
char	*str_replace(char *s, char pattern, char replacement)
{
	char	*start;

	start = s;
	while (*s)
	{
		if (*s  == pattern)
			*s = replacement;
		s++;
	}
	return (start);
}

/*
**  Warning! 
**  s is always freed. suffix is always not freed
**	In case of NULL argument return NULL
*/

char	*add_suffix(char *s, char *suffix)
{
	int		len;
	char	*new;

	if (!s || !suffix)
	{
		free(s);
		return (0);
	}
	len = ft_strlen(s);
	new = ft_strnew(len + ft_strlen(suffix));
	if (!new)
	{
		free(s);
		return (0);
	}
	ft_strcpy(new, s);
	ft_strcpy(new + len, suffix);
	free(s);
	return (new);
}


/*
**  Warning! 
**  s is always freed. prefix is always not freed
**	In case of NULL argument return NULL
*/

char	*add_prefix(char *s, char *prefix)
{
	int		len;
	char	*new;

	if (!s || !prefix)
	{
		free (s);
		return (0);
	}
	len = ft_strlen(prefix);
	new = ft_strnew(len + ft_strlen(s));
	if (!new)
	{
		free(s);
		return (0);
	}
	ft_strcpy(new, prefix);
	ft_strcpy(new + len, s);
	free(s);
	return (new);
}

char	*prepend_zeros(char *s, int n)
{
	char	*prefix;
	
	if (!(prefix = char_n_dup('0', n)))
		return (0);
	s = add_prefix(s, prefix);
	free(prefix);
	return (s);
}

/*
**	Insert string src into n-th position of string dst
**	free src and dst
*/

char	*str_insert(char *dst, char *src, int pos)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(ft_strlen(src) + ft_strlen(dst));
	if (!new)
		return (0);
	while (i < pos)
	{
		new[i] = dst[i];
		i++;
	}
	ft_strcat(new, src);
	ft_strcat(new, dst + i);
	free(src);
	free(dst);
	return (new);
}
