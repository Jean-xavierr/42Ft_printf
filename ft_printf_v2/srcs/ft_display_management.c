/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_management.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:00:06 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/19 10:08:46 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_putstr(char *s, t_data *data)
{
	int	i;

	i = 0;
	if (data->precision > 0)
		while (i < data->precision && s[i])
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
}
