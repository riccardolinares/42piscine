/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:10:47 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 18:18:17 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
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
	if (check_error_in_base(base))
	{
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
			nbr *= ft_strlen(base);
			nbr += (unsigned int)(is_in_base(base, charptr) - base);
			charptr++;
		}
	}
	return (int)(nbr * minus);
}
