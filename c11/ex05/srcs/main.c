/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:04:49 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 17:36:54 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	char *charptr;

	charptr = str;
	while (*charptr != 0)
	{
		write(1, charptr, 1);
		charptr++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int nbr_unsigned;

	if (nb < 0)
	{
		nbr_unsigned = (unsigned int)(-1 * nb);
		ft_putchar('-');
	}
	else
		nbr_unsigned = (unsigned int)nb;
	if (nbr_unsigned >= 10)
	{
		ft_putnbr(nbr_unsigned / 10);
		ft_putnbr(nbr_unsigned % 10);
	}
	else
		ft_putchar(nbr_unsigned + '0');
}

int		ft_atoi(char *str)
{
	int num;
	int i;
	int minus;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-' && minus > 0)
			minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10;
		num = num + (str[i] - '0');
		i++;
	}
	return (num);
}

void	make_operation(int a, int b, int (*operation)(int, int))
{
	ft_putnbr(operation(a, b));
	write(1, "\n", 1);
}

int		addition(int a, int b)
{
	return (a + b);
}

int		substraction(int a, int b)
{
	return (a - b);
}

int		multiplication(int a, int b)
{
	return (a * b);
}

int		division(int a, int b)
{
	return (a / b);
}

int		modulo(int a, int b)
{
	return (a % b);
}

int		main(int argc, char **argv)
{
	if (*argv[2] == '+')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), addition);
	else if (*argv[2] == '-')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), substraction);
	else if (*argv[2] == '*')
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), multiplication);
	else if (*argv[2] == '/')
	{
		if (ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : division by zero\n");
			return (0);
		}
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), division);
	}
	else if (*argv[2] == '%')
	{
		if (ft_atoi(argv[3]) == 0)
		{
			ft_putstr("Stop : modulo by zero\n");
			return (0);
		}
		make_operation(ft_atoi(argv[1]), ft_atoi(argv[3]), modulo);
	}
	return (0);
}
