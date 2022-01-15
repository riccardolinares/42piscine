/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:55:25 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/05 20:22:02 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (max <= min)
	{
		*range = 0;
		return (0);
	}
	if (!(*range = malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (min < max)
	{
		*(*range + i) = min;
		min++;
		i++;
	}
	return (i);
}
