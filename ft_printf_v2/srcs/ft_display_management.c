/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:00:06 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/22 11:29:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putstr(char *s, t_data *data)
{
	int	i;
	int	precision;

	i = 0;
	precision = data->precision;
	if ((data->convers != 's' || data->convers != 'c') && (data->precision > 0
	&& s[0] != '0'))
		precision = -1;
	if (precision >= 0)
		while (i < precision && s[i])
		{
			write(1, &s[i++], 1);
			data->return_printf++;
		}
	else
		while (s[i])
		{
			write(1, &s[i++], 1);
			data->return_printf++;
		}
}

void		ft_display_management(t_data *data)
{
	if (data->convers == 'c')
		ft_putchar((char)data->arg, data);
	else if (data->convers == 's')
		ft_putstr((char *)data->arg, data);
	else if (data->convers == 'd' || data->convers == 'i')
		ft_putstr(ft_itoa((int)data->arg), data);
	else if (data->convers == 'u')
		ft_putstr(ft_unsigned_itoa((unsigned int)data->arg), data);
}
