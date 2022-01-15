/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:27:08 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 17:32:42 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (tab[i])
	{
		if (f(tab[i] != 0))
			counter++;
		i++;
	}
	return (counter);
}
