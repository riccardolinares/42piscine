/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:31:22 by rlinares          #+#    #+#             */
/*   Updated: 2020/10/30 16:12:31 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return len;
}

void	print_last_word(char *str)
{
	int		i;

	i = 0;
	while (!(((str[i] && (str[i] >= 9  && str[i] <= 13)) || str[i] == 32)))
	{
		write(1, &str[i], 1);
		i++;
	}
}
	
int 	main(int argc, char **argv)
{
	int len;
	int k;
	char *str;

	str = argv[1];
	len = 0;
	k = 0;
	len = ft_strlen(str);
	if (*str && argc > 0)
	{
		while (str[k] && str[len - 1] && ((str[k] >= 9  && str[k] <= 13 ) || str[k] == 32))
			len--;
		while (!(str[k] && str[len - 1] && ((str[k] >= 9  && str[k] <= 13) || str[k] == 32)))
			len--;
		print_last_word(&str[len + 1]);
	}	
}
