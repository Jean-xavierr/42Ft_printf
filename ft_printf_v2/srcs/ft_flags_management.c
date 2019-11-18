/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_management.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:11:46 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/18 15:28:59 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_width(t_data *data)
{
	int	i;

	i = 0;
	while (i++ < data->width)
		ft_putchar(' ', data);
	ft_display_management(data);	
}

static void		ft_flag_zero(t_data *data)
{
	int	precision;

	precision = data->precision;
	while (precision++ < data->width)
		ft_putchar('0', data);
	ft_display_management(data);
}

static void		ft_flag_minus(t_data *data)
{
	ft_display_management(data);
	while (data->precision++ < data->width)
		ft_putchar(' ', data);
}

void			ft_flags_management(t_data *data)
{
	if (data->flags == '-')
		ft_flag_minus(data);
	else if (data->flags == '0')
		ft_flag_zero(data);
	else if (data->width > 0)
		ft_flag_width(data);
	else
		ft_display_management(data);
}
