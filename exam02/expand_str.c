/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 11:38:25 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/06 12:44:58 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


int	ft_lastletter(char *str)
{
	int ls;

	ls = ft_strlen(str) - 1;
	while (str[ls] && ((str[ls] >= 9 && str[ls] <= 13) || str[ls] == 32))
		ls--;
	return (ls);
}

int main(int argc, char **argv)
{
	char	*res;
	int		len;
	int		i;
	int		print_space;
	int		last_letter;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	last_letter = ft_lastletter(argv[1]);
	len = ft_strlen(argv[1]);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (argv[1][i] && ((argv[1][i] >= 9 && argv[1][i] <= 13) ||
				argv[1][i] == 32))
		i++;
	print_space = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 33 && argv[1][i] <= 126)
		{
			write(1, &argv[1][i], 1);
			print_space = 1;
		}
		else if (((argv[1][i] >= 9 && argv[1][i] <= 13) ||
			argv[1][i] == 32) && print_space == 1 && i < (last_letter))
		{
			write(1, "   ", 3);
			print_space = 0;
		}
		i++;
	}
	return (0);
}
