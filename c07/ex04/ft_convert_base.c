/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:10:12 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 16:06:08 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);

void	ft_encodenbr_base(int nbr, char *base, char *nb_dest);

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
			|| *checkbase == ' ' || *checkbase <= 31)
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

char	*is_in_base(char *base, char *to_find)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (*to_find == base[i])
			return (base + i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	nbr;
	int				minus;
	char			*charptr;

	nbr = 0;
	minus = 1;
	charptr = str;
	while (*charptr == ' ' || (*charptr >= 9 && *charptr <= 13))
		charptr++;
	while (*charptr == '-' || *charptr == '+')
	{
		if (*charptr == '-')
			minus *= -1;
		charptr++;
	}
	while (is_in_base(base, charptr))
	{
		nbr = nbr * ft_strlen(base);
		nbr = nbr + (unsigned int)(is_in_base(base, charptr) - base);
		charptr++;
	}
	return (int)(nbr * minus);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb_int;
	char	*nb_converti;

	if (!(check_error_in_base(base_from) && check_error_in_base(base_to)))
		return (0);
	nb_converti = malloc(34);
	nb_int = ft_atoi_base(nbr, base_from);
	ft_encodenbr_base(nb_int, base_to, nb_converti);
	return (nb_converti);
}
