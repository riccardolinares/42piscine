/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:31:46 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 18:17:58 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_error_in_base(char *base)
{
	char	*checkbase;
	int		i;

	checkbase = base;
	if (*base == 0 || *(base + 1) == 0)
		return (0);
	while (*checkbase)
	{
		if (*checkbase == '+' || *checkbase == '-'
			|| *checkbase <= 31)
			return (0);
		i = 1;
		while (*(checkbase + i))
		{
			if (*(checkbase + i) == *checkbase)
				return (0);
			i++;
		}
		checkbase++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int lenbase;
	unsigned int nbr_unsigned;

	if (check_error_in_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr_unsigned = (unsigned int)(-1 * nbr);
		}
		else
			nbr_unsigned = (unsigned int)nbr;
		lenbase = ft_strlen(base);
		if (nbr_unsigned >= lenbase)
		{
			ft_putnbr_base(nbr_unsigned / lenbase, base);
			ft_putnbr_base(nbr_unsigned % lenbase, base);
		}
		else
		{
			write(1, (base + nbr_unsigned), 1);
		}
	}
}
