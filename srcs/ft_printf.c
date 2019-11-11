/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 10:55:22 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/11 14:14:53 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_convers(char c)
{
	int		i;
	char	*storage_convers;

	i = 0;
	storage_convers = "csduxXp";
	while (storage_convers[i])
	{
		if (storage_convers[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_is_flags(char c)
{
	int		i;
	char	*storage_flags;

	i = 0;
	storage_flags = "-0123456789.*";
	while (storage_flags[i])
	{
		if (storage_flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_string(const char *s, int i, va_list ap, t_storage *storage)
{
	while ((ft_is_convers(s[i]) || ft_is_flags(s[i])) && s[i])
	{
		if (ft_is_flags(s[i]))
			i = ft_check_flags(s, i, ap, storage);
		else if (ft_is_convers(s[i]))
		{
			ft_print_convers(s, i, ap, storage);
			i++;
		}
		else
			i++;
	}
	return (i - 1);
}

void	ft_printf(const char *s, ...)
{
	int				i;
	va_list			ap;
	t_storage		storage;

	i = 0;
	va_start(ap, s);
	storage.return_printf = 0;
	storage = ft_init_struct(storage);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar(s[i]);
			storage.return_printf++;
		}
		if (s[i] == '%')
			i = ft_check_string(s, i + 1, ap, &storage);
		i++;
	}
	printf("|flags: %c flags_nb: %d|\t width: %d precision: %c|\n", storage.flags, storage.flags_nb, storage.width, storage.precision);
	va_end(ap);
}
