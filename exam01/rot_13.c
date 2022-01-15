/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:14:21 by rlinares          #+#    #+#             */
/*   Updated: 2020/10/30 15:29:44 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert(char c)
{
	char r;
	if (c >= 'a' && c <= 'z')
		r = "abcdefghijklmnopqrstuvwxyz"[(c - 'a' + 13) % 26];
	else if (c >= 'A' && c <= 'Z')
		r = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[(c - 'a' + 13) % 26];
	else 
		r = c;
	write(1, &r, 1);
}

int		main(int argc, char **argv)
{
	int k;

	k = 0;
	while (argc > 0 && argv[1][k])
	{
		ft_convert(argv[1][k]);
		k++;
	}
	write(1, "\n", 1);
	return (0);
}
