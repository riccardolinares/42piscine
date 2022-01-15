/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprim.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 14:37:11 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/06 14:55:02 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int num;
	int old_num;
	int i;
	int *res;

	if (argc != 2)
	{
		printf("invalid \n");
		return (0);
	}
	num = atoi(argv[1]);
	printf("stampo il num %d\n", num);
	i = 2;
	old_num = 1;
	while (i <= num)
	{
		if ( num % i == 0)
		{
			printf("%d", i);
			if (num == i)
				return (0);
			num = num / i;
			printf("*");
		}
		else
		{
			i++;
		}
	}

	return (0);
}
