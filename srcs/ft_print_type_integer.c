/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:15:13 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 11:18:10 by jereligi         ###   ########.fr       */
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
