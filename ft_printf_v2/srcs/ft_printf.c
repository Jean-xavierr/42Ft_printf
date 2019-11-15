/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:44:05 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/15 15:36:40 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_string(int i, t_data *data)
{
	int		n;
	char	*tmp;
	
	n = 0;
	tmp = 0;
	ft_reinit_flags(data);
	while ((ft_check_set(data->str[i]) &&  data->str[i]))
	{
		data->set = ft_strjoin(data->set, &data->str[i]);
		i++;
	}
	printf("set = %s", data->set);
	while (data->set[n++])
	{
		if (ft_is_char(data->set[n]))
		{
			write(1, "print class", 11);
			write(1, &n, 1);
			write(1, "\n", 1);
			//ft_print(data);
		}	
		else if (data->set[n + 1] == '\0')
		{
			write(1, "call", 4);
			//ft_call_hub(data);
		}
	}
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
