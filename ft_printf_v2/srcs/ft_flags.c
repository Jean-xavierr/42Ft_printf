/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:41:33 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/16 16:12:11 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_flag_precision(t_data *data)
{



}

static void		ft_flag_width(t_data *data)
{


}

static void		ft_flag_zero(t_data *data)
{


}

static void		ft_flag_minus(t_data *data)
{
	ft_print_convers(data);

}

void			ft_flags_management(t_data *data)
{
	if (data->flags == '-')
		ft_flag_minus(data);
	else if (data->flags == '0')
		ft_flag_zero(data);
	else if (data->width > 0)
		ft_flag_width(data);
	else if (data->precision)
		ft_flag_precision(data);
	else
		ft_print_convers(data);
}
