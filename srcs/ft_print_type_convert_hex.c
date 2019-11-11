/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_convert_hex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:15:49 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 13:05:56 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
