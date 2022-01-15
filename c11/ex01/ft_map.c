/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:31:49 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 17:33:37 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *res;
	int i;

	i = 0;
	if (!(res = (int *)malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}
