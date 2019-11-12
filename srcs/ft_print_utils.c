/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 11:57:40 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/12 11:21:17 by jereligi         ###   ########.fr       */
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

	i = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int			ft_check_flags(const char *s, int i, va_list ap, t_data *data)
{
	if (s[i] == '-')
	{
		data->flags = s[i];
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			data->flags_nb = data->flags_nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '0' && s[i - 1] != '-')
	{
		data->flags = '0';
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			data->flags_nb = data->flags_nb * 10 + s[i] - 48;
			i++;
		}
	}
	else if (s[i] >= '0' && s[i] <= '9')
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			data->width = data->width * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '.')
	{		
		data->precision = s[i];
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			data->precision_nb = data->precision_nb * 10 + s[i] - 48;
			i++;
		}
	}
	if (s[i] == '*')
	{
		data->precision = s[i];
		i++;
		if (ft_is_convers(s[i]))
			data->precision_nb = va_arg(ap, int);
		else
			while (s[i] >= '0' && s[i] <= '9')
			{
				data->precision_nb = data->precision_nb * 10 + s[i] - 48;
				i++;
			}
	}
	return (i);
}

void		ft_print_convers(const char *s, int i, va_list ap, t_data *data)
{
	if (s[i] == 'c')
		ft_print_type_c(ap, data);
	if (s[i] == 's')
		ft_print_type_s(ap, data);
	if (s[i] == 'd' || s[i] == 'u' || s[i] == 'i')
		ft_print_type_integer(s[i], ap, data);
/*	if (s[i] == 'x' || s[i] == 'X')
		ft_print_type_convert_hex(s[i], ap, data);
	if (s[i] == 'p')
		ft_print_type_p(ap, data);*/
}

t_data	ft_init_struct(t_data data)
{
	data.flags = '~';
	data.flags_nb = 0;
	data.width = 0;
	data.precision = '0';
	data.precision_nb = 0;
	data.return_printf = 0;
	return (data);
}
