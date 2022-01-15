/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:55:45 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 14:48:28 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup_custom(char *src, char *end)
{
	char *cpy;
	char *start;

	if (!(cpy = (char *)malloc((end - src + 2) * sizeof(char))))
		return (0);
	start = cpy;
	while (src != end)
		*(cpy++) = *(src++);
	*cpy = '\0';
	return (start);
}

int		is_sep(char str, char *charset)
{
	while (*charset)
	{
		if (str == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		final_len(char *str, char *charset, char *begin, char *end)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, charset))
		{
			str++;
			begin = 0;
			end = 0;
		}
		begin = str;
		while (*str && !is_sep(*str, charset))
		{
			end = str;
			str++;
		}
		if (end)
			count++;
	}
	return (count);
}

char	*real_split(char **str, char *c_set, char **begin)
{
	char *end;

	end = 0;
	while (**str && is_sep(**str, c_set))
	{
		(*str)++;
		*begin = 0;
		end = 0;
	}
	*begin = *str;
	while (**str && !is_sep(**str, c_set))
	{
		end = *str;
		(*str)++;
	}
	return (end);
}

char	**ft_split(char *str, char *charset)
{
	int		set_len;
	int		i;
	char	**strs;
	char	*begin;
	char	*end;

	end = 0;
	begin = 0;
	set_len = final_len(str, charset, 0, 0);
	if (!(strs = (char **)malloc((set_len + 1) * sizeof(char *))))
		return (0);
	i = 0;
	while (*str)
	{
		end = real_split(&str, charset, &begin);
		if (end)
			strs[i++] = ft_strdup_custom(begin, end + 1);
	}
	strs[i] = 0;
	return (strs);
}
