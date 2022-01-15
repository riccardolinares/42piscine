/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 10:31:45 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 13:04:03 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_num(char c, int num)
{
	if (num == 0)
		num = c - '0';
	else
		num = (num * 10) + (c - '0');
	return (num);
}

int	ft_atoi(char *str)
{
	int	i;
	int	num;
	int	minus;

	i = 0;
	num = 0;
	minus = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = ft_num(str[i], num);
		i++;
	}
	return (num * minus);
}
