/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:32:27 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/19 17:05:33 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int		ft_strlen_nb_hex(long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}*/

int			ft_get_strlen(t_data *data)
{
	if (data->convers == 'c')
		return (1);
	else if (data->convers == 's')
		return (ft_strlen((char *)data->arg));
/*	else if (data->convers == 'p')
		return (ft_strlen_nb_hex((unsigned long)data->arg) + 2 );*/
	else if (data->convers == 'd' || data->convers == 'i')
		return (ft_strlen(ft_itoa((int)data->arg)));
/*	else if (data->convers == 'u')
		return (ft_strlen(ft_itoa((int)data->arg)));
	else if (data->convers == 'x' || data->convers == 'X')
		return (ft_strlen_nb_hex((unsigned int)data->arg));*/
	return (0);
}
