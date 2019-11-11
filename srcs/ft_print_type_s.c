/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 11:14:43 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 16:42:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_flags_zero(va_list ap, t_storage *storage)
{
	int 	i;
	char	*s;
	
	s = va_arg(ap, char *);
	i = ft_strlen(s);
	while (i++ < storage->flags_nb)
		write(1, "0", 1);
	while (*s)
		ft_putchar(*s++);
}

static void		ft_print_flags_minus(va_list ap, t_storage *storage)
{
	int 	i;
	char	*s;
	
	s = va_arg(ap, char *);
	i = ft_strlen(s);
	while (*s)
		ft_putchar(*s++);
	while (i++ < storage->flags_nb)
		write(1, " ", 1);
}

static void		ft_print_flags_width_precision(va_list ap, t_storage *storage)
{
	int 	i;
	char	*s;
	
	s = va_arg(ap, char *);
	i = ft_strlen(s);	
	if (storage->width >= 1)
		while (i++ < storage->width)
			write(1, " ", 1);
	else if (storage->precision == '*')
		while (i++ < storage->precision_nb)
			write(1, " ", 1);
	while (*s)
		ft_putchar(*s++);
}

static void		ft_print_flags_point(va_list ap, t_storage *storage)
{
	int		i;
	char	*s;

	i = 0;
	s = 0;
	s = va_arg(ap, char *);
	while (storage->precision_nb-- > 0 && s[i])
		ft_putchar(s[i++]);
}

void			ft_print_type_s(va_list ap, t_storage *storage)
{
	if (storage->flags == '0')
		ft_print_flags_zero(ap, storage);
	else if (storage->flags == '-')
		ft_print_flags_minus(ap, storage);
	else if (storage->width >= 1 || storage->precision == '*')
		ft_print_flags_width_precision(ap, storage);
	else if (storage->precision == '.')
		ft_print_flags_point(ap, storage);
	else
	{
		char *s;
		
		s = va_arg(ap, char *);
		while (*s)
			ft_putchar(*s++);
	}
}
