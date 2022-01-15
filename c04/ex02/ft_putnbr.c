/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:14:14 by rlinares          #+#    #+#             */
/*   Updated: 2020/10/28 10:31:10 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int		index;
	char	reminder;

	if (nb > 9)
	{
		index = nb / 10;
		reminder = (nb % 10) + '0';
		ft_putnbr(index);
		ft_putchar(reminder);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			ft_putnbr(147483648);
		}
		else
			ft_putnbr((nb * -1));
	}
	else
		ft_putchar((nb + '0'));
}
