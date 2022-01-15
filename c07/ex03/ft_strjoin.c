/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:20:43 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/05 11:45:36 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_fill_arr(int size, char **strs, char *sep, char *res)
{
	int i;
	int k;
	int m;

	i = 0;
	m = 0;
	while (i < size)
	{
		k = 0;
		while (strs[i][k])
			res[m++] = strs[i][k++];
		k = 0;
		while (sep[k] && i < (size - 1))
			res[m++] = sep[k++];
		i++;
	}
	res[m] = '\0';
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		tot_len;

	if (size < 1)
	{
		if (!(res = (char *)malloc(1)))
			return (0);
	}
	else
	{
		i = 0;
		tot_len = 0;
		while (i < size && strs[i])
		{
			tot_len = tot_len + ft_strlen(strs[i]);
			i++;
		}
		if (!(res = (char *)malloc(tot_len + size * ft_strlen(sep) + 1)))
			return (0);
	}
	return (ft_fill_arr(size, strs, sep, res));
}
