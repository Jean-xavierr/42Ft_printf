/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:15:13 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/12 11:47:33 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int nbr)
{
	long nb;

	nb = (long)nbr;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putnbr_unsigned(unsigned nbr)
{
	if (nbr > 9)
	{
		ft_putnbr_unsigned(nbr / 10);
		ft_putnbr_unsigned(nbr % 10);
	}
	else
		ft_putchar(nbr + '0');
}

static void		ft_print_flags_zero(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;
	
	nb = va_arg(ap, long);
	i = ft_strlen_nb(nb);
	while (i++ < data->flags_nb)
		write(1, "0", 1);
	if (c == 'd' || c == 'i')
		ft_putnbr(nb);
	else
		ft_putnbr_unsigned(nb);
}

static void		ft_print_flags_minus(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb(nb);
	if (c == 'd' || c == 'i')
		ft_putnbr(nb);
	else
		ft_putnbr_unsigned(nb);
	while (i++ < data->flags_nb)
		write(1, " ", 1);
}

static void		ft_print_flags_width_precision(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb(nb);
	if (data->width >= 1)
		while (i++ < data->width)
			write(1, " ", 1);
	else if (data->precision == '*')
		while (i++ < data->precision_nb)
			write(1, " ", 1);
	if (c == 'd' || c == 'i')
		ft_putnbr(nb);
	else
		ft_putnbr_unsigned(nb);
}

static void		ft_print_flags_point(char c, va_list ap, t_data *data)
{
	int		i;
	long	nb;

	nb = va_arg(ap, long);
	i = ft_strlen_nb(nb);
	while (data->precision_nb-- > i)
		write(1, "0", 1);
	if (c == 'd' || c == 'i')
		ft_putnbr(nb);
	else
		ft_putnbr_unsigned(nb);
}

void			ft_print_type_integer(char c, va_list ap, t_data *data)
{
	if (data->flags == '0')
		ft_print_flags_zero(c, ap, data);
	else if (data->flags == '-')
		ft_print_flags_minus(c, ap, data);
	else if (data->width >= 1 || data->precision == '*')
		ft_print_flags_width_precision(c, ap, data);
	else if (data->precision == '.')
		ft_print_flags_point(c, ap, data);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(ap, long));
	else
		ft_putnbr_unsigned(va_arg(ap, long));
}
