/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:44:05 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/18 11:58:52 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_is_width_precision(int i, t_data *data)
{
	if (data->set[i] >= '0' && data->set[i] <= '9')
		while (data->set[i] >= '0' && data->set[i] <= '9')
			data->width = data->width * 10 + (data->set[i++] - '0');
	else if (data->set[i] == '*')
	{
		if (ft_is_convers(data->set[i + 1]) || data->set[i + 1] == '*')
		{
			data->width = va_arg(data->ap, int);
			if (data->width < 0)
			{
				data->flags = '-';
				data->flags_nb = data->width * -1;
				data->width = 0;
			}
			i++;
		}
		else
			while (data->set[i] >= '0' && data->set[i] <= '9')
				data->width = data->width * 10 + (data->set[i++] - '0');
	}
	return (i);
}

int		ft_check_is_minus_or_zero(int i, t_data *data)
{
	if (data->set[i] == '-')
	{
		data->flags = '-';
		i++;
		while (data->set[i] >= '0' && data->set[i] <= '9')
			data->flags_nb = data->flags_nb * 10 + (data->set[i++] - '0');
	}
	else if (data->set[i] == '0' && data->flags != '-' && data->flags != '0')
	{
		data->flags = '0';
		while (data->set[i] >= '0' && data->set[i] <= '9')
			data->flags_nb = data->flags_nb * 10 + (data->set[i++] - '0');
	}
	return (i);
}

void	ft_check_flags(t_data *data)
{
	int i;
	int	n;

	i = 0;
	n = 0;
	while (data->set[i])
	{
		if (i < (n = ft_check_is_minus_or_zero(i, data)))
			i = n;
		else if (i < (n = ft_check_is_width_precision(i, data)))
			i = n;
		else if (data->set[i++] == '.')
		{
			if (data->set[i] != '*')
				while (data->set[i] >= '0' && data->set[i] <= '9')
					data->precision_nb = data->precision_nb *
						10 + (data->set[i++] - '0');
			else if (data->set[i++] == '*')
				data->precision_nb = va_arg(data->ap, int);
		}
		else if (i < (n = ft_check_is_width_precision(i, data)))
			i = n;
		else
			i++;
	}
}

int		ft_check_string(int i, t_data *data)
{
	int		n;
	char	*tmp;
	
	n = 0;
	tmp = 0;
	ft_reinit_flags(data);
	while ((ft_check_set(data->str[i]) && data->str[i]))
	{
		data->set = ft_strjoin_char(data->set, data->str[i]);
		i++;
	}
	printf("set = %s\n", data->set);
	ft_check_flags(data);
	printf("flags = %c\n", data->flags);
	printf("flags_nb = %d\n", data->flags_nb);
	printf("flags_pre = %d\n", data->precision_nb);
	printf("flags_width = %d\n\n", data->width);
/*	while (data->set[n++])
	{
		if (ft_is_char(data->set[n]))
		{
			write(1, "print class", 11);
			//ft_print(data);
			break ;
		}	
		else if (data->set[n + 1] == '\0')
		{
			write(1, "call", 4);
			//ft_call_hub(data);
		}
	}*/
	return (i);
}

int		ft_printf(const char *s, ...)
{
	int			i;
	t_data		data;

	i = 0;
	ft_init(s, &data);
	va_start(data.ap, s);
	while (data.str[i])
	{
		if (data.str[i] == '%' && data.str[i + 1] == '%')
		{
			ft_putchar(data.str[i], &data);
			i += 2;
		}
		else if (data.str[i] != '%')
			ft_putchar(data.str[i++], &data);
		else if (data.str[i] == '%')
			i = ft_check_string(i + 1, &data);
	}
	return (data.return_printf);
}