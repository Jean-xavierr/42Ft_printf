/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_convert_hex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:15:49 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/12 14:42:58 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_strlen_nb_hex(long nb)
{
	int	i;

	i = 1;
	while (nb >= 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_convert_dec_to_hex(unsigned long nbr)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
		ft_convert_dec_to_hex(nbr / 16);
	ft_putchar(base[nbr % 16]);
}

void	ft_convert_dec_to_HEX(unsigned long nbr)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
		ft_convert_dec_to_HEX(nbr / 16);
	ft_putchar(base[nbr % 16]);
}

static void	ft_print_flags_zero(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;
	
	nb = va_arg(ap, long);
	i = ft_strlen_nb_hex(nb);
	while (i++ < data->flags_nb)
		write(1, "0", 1);
	if (c == 'x')
		ft_convert_dec_to_hex(nb);
	else
		ft_convert_dec_to_HEX(nb);
}

static void ft_print_flags_minus(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb_hex(nb);
	if (c == 'x')
		ft_convert_dec_to_hex(nb);
	else if (c == 'X')
		ft_convert_dec_to_HEX(nb);
	while (i++ < data->flags_nb)
		write(1, " ", 1);
}

static void ft_print_flags_width_precision(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb_hex(nb);
	if (data->width >= 1)
		while (i++ < data->width)
			write(1, " ", 1);
	else if (data->precision == '*')
		while (i++ < data->precision_nb)
			write(1, " ", 1);
	if (c == 'x')
		ft_convert_dec_to_hex(nb);
	else
		ft_convert_dec_to_HEX(nb);
}

static void ft_print_flags_point(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb_hex(nb);
	while (i++ < data->precision_nb)
		write (1, "0", 1);
	if (c == 'x')
		ft_convert_dec_to_hex(nb);
	else
		ft_convert_dec_to_HEX(nb);
}

void		ft_print_type_convert_hex(char c, va_list ap, t_data *data)
{
	if (data->flags == '0')
		ft_print_flags_zero(c, ap, data);
	else if (data->flags == '-')
		ft_print_flags_minus(c, ap, data);
	else if (data->width >= 1 || data->precision == '*')
		ft_print_flags_width_precision(c, ap, data);
	else if (data->precision == '.')
		ft_print_flags_point(c, ap, data);
	else if (c == 'x')
		ft_convert_dec_to_hex(va_arg(ap, long));
	else if (c == 'X')
		ft_convert_dec_to_hex(va_arg(ap, long));
}
