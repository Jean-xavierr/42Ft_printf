/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:16:02 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/12 15:24:12 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_flags_zero(int	i, va_list ap, t_data *data)
{
	unsigned long	memory_add;
	
	memory_add = (unsigned long)va_arg(ap, void*);
	ft_putstr("0x");
	if	(data->flags == '0')
		while (i++ < data->flags_nb)
			write(1, "0", 1);
	else if (data->precision == '.')
	{
		i = 12;
		while (i++ < data->precision_nb)
			write(1, "0", 1);
	}
	ft_convert_dec_to_hex(memory_add);
}

static void		ft_print_flags_minus(int i, va_list ap, t_data *data)
{
	unsigned long	memory_add;

	memory_add = (unsigned long)va_arg(ap, void *);
	ft_putstr("0x");
	ft_convert_dec_to_hex(memory_add);
	while (i++ < data->flags_nb)
		write (1, " ", 1);
}

static void		ft_print_flags_width_precision(int i, va_list ap, t_data *data)
{
	unsigned long	memory_add;

	memory_add = (unsigned long)va_arg(ap, void *);
	if (data->width >= 1)
		while (i++ < data->width)
			write(1, " ", 1);
	if (data->precision == '*')
		while (i++ < data->precision_nb)
			write(1, " ", 1);
	ft_putstr("0x");
	ft_convert_dec_to_hex(memory_add);
}

void			ft_print_type_p(va_list ap, t_data *data)
{
	int				i;

	i = 14;
	if (data->flags == '0' || data->precision == '.')
		ft_print_flags_zero(i, ap, data);
	else if (data->flags == '-')
		ft_print_flags_minus(i, ap, data);
	else if (data->width >= 1 || data->precision == '*')
		ft_print_flags_width_precision(i, ap, data);
	else
	{
		unsigned long	memory_add;
		
		memory_add = (unsigned long)va_arg(ap, void *);
		ft_putstr("0x");
		ft_convert_dec_to_hex(memory_add);
	}
}
