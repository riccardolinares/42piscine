/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlinares <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:24:44 by rlinares          #+#    #+#             */
/*   Updated: 2020/11/12 14:56:38 by rlinares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (0);
}

void	strev(char *str, int offset_of_center)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i + offset_of_center];
		str[i + offset_of_center] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

void	ft_encodenbr_base(int nbr, char *base, char *nb_dest)
{
	unsigned int	lenbase;
	unsigned int	unbr;
	int				i;

	i = 0;
	if (nbr < 0)
	{
		nb_dest[i++] = '-';
		unbr = (unsigned int)(-1 * nbr);
	}
	else
		unbr = (unsigned int)nbr;
	lenbase = ft_strlen(base);
	if (unbr == 0)
		nb_dest[i++] = *(base);
	while (unbr > 0)
	{
		nb_dest[i++] = *(base + (unbr % lenbase));
		unbr = unbr / lenbase;
	}
	nb_dest[i] = 0;
	(nbr < 0) ? strev(nb_dest, 1) : strev(nb_dest, 0);
}
