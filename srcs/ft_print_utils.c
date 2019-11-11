/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:57:40 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 14:15:59 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int			ft_strlen_nb(long nb)
{
	int	i;

	i = 0;
	while (nb / 10)
		i++;
	return (i);
}

int			ft_check_flags(const char *s, int i, va_list ap, t_storage *storage)
{
	if (s[i] == '-')
	{
		storage->flags = s[i];
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			storage->flags_nb = storage->flags_nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '0' && s[i - 1] != '-')
	{
		storage->flags = '0';
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			storage->flags_nb = storage->flags_nb * 10 + s[i] - 48;
			i++;
		}
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			storage->width = storage->width * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '.')
	{		
		storage->precision = s[i];
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			storage->precision_nb = storage->precision_nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '*')
	{
		storage->precision = s[i];
		i++;
		if (ft_is_convers(s[i]))
			storage->precision_nb = va_arg(ap, int);
		else
			while (s[i] >= '0' && s[i] <= '9')
			{
				storage->precision_nb = storage->precision_nb * 10 + s[i] - 48;
				i++;
			}
	}
	return (i);
}

void		ft_print_convers(const char *s, int i, va_list ap, t_storage *storage)
{
	if (s[i] == 'c')
		ft_print_type_c(ap, storage);
/*	if (s[i] == 's')
		ft_print_type_s(ap, storage);
	if (s[i] == 'd' || s[i] == 'u' || s[i] == 'i')
		ft_print_type_integer(s[i], ap, storage);
	if (s[i] == 'x' || s[i] == 'X')
		ft_print_type_convert_hex(s[i], ap, storage);
	if (s[i] == 'p')
		ft_print_type_p(ap, storage);*/
}

t_storage	ft_init_struct(t_storage storage)
{
	storage.flags = '~';
	storage.flags_nb = 0;
	storage.width = 0;
	storage.precision = '0';
	storage.precision_nb = 0;
	storage.return_printf = 0;
	return (storage);
}
