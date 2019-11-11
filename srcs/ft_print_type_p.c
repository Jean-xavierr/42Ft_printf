/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:16:02 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 13:04:14 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_type_p(va_list ap, t_storage *storage)
{
	unsigned long	memory_add;

	storage->return_printf = 0;
	memory_add = (unsigned long)va_arg(ap, void*);
	ft_putstr("0x");
	ft_convert_dec_to_hex(memory_add);
}
