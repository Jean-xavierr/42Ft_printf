/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:55:15 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 13:33:03 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_storage
{
		char		flags;
		int			flags_nb;
		int			width;
		char		precision;
		int			precision_nb;
		int			return_printf;
}					t_storage;

void	ft_printf(const char *s, ...);
void	ft_print_convers(const char *s, int i, va_list ap, t_storage *storage);
int		ft_check_flags(const char *s, int i, t_storage *storage);

t_storage ft_init_struct(t_storage storage);

void	ft_print_type_c(va_list ap, t_storage *storage);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_convert_dec_to_hex(unsigned long nbr);

//

void	ft_print_type_s(va_list ap, t_storage *storage);
void	ft_print_type_integer(char c,va_list ap, t_storage *storage);
void	ft_print_type_convert_hex(char c, va_list ap, t_storage *storage);
void	ft_print_type_p(va_list ap, t_storage *storage);

#endif
