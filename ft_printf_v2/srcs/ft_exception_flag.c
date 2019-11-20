/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exception_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:43:33 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/20 14:15:24 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_exception_flag_zero(t_data *data)
{
	int		precision;
	char	*s;

	ft_putchar('-', data);
	if (data->precision > 0)
		precision = data->precision;
	else
		precision = ft_get_strlen(data);
	while (precision++ < data->width)
		ft_putchar('0', data);
	s = ft_itoa((int)data->arg);
	ft_putstr(&s[1], data);
}

int			ft_nb_is_negative(t_data *data)
{
	char *str_nb;

	str_nb = 0;
	if (data->convers == 'd' || data->convers == 'i')
	{
		str_nb = ft_itoa((int)data->arg);
		if (str_nb[0] == '-')
			return (1);
	}
	return (0);
}
