/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:50:54 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/15 15:29:52 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->return_printf++;
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_reinit_flags(t_data *data)
{
	if (!(data->set = (char *)malloc(sizeof(char *))))
		return ;
	data->flags = '~';
	data->flags_nb = 0;
	data->width = 0;
	data->precision = 0;
	data->precision_nb = 0;
}

void	ft_init(const char *s, t_data *data)
{
	data->str = (char *)s;
	data->set = 0;
	data->flags = '~';
	data->flags_nb = 0;
	data->width = 0;
	data->precision = 0;
	data->precision_nb = 0;
	data->return_printf = 0;
}
