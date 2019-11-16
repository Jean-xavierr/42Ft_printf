/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:42:21 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/16 15:44:10 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct		s_data
{
	va_list		ap;
	char		*str;
	char		*set;
	char		flags;
	int			flags_nb;
	int			width;
	int			precision_nb;
	int			return_printf;
}					t_data;

// ---> ft_printf.c <---
int					ft_check_string(int i, t_data *data);
int					ft_printf(const char *s, ...);

// ---> ft_utils.c <---
void				ft_putchar(char c, t_data *data);
int					ft_strlen(char *s);
void				ft_reinit_flags(t_data *data);
void				ft_init(const char *s, t_data *data);

// ---> ft_check_set.c <---
int					ft_is_flags(char c);
int					ft_is_convers(char c);
int					ft_is_char(char c);
int					ft_check_set(char c);

// ---> ft_strjoin.c <---
char				*ft_strjoin_char(char *s1, char c);

// ---> ft_display_management <---
void		ft_print_convers(t_data *data);
void		ft_display_management(t_data *data);

// ---> ft_flags.c <---
void		ft_flags_management(t_data *data);

// ---> ft_itoa.c <---
char		*ft_itoa(int n);

#endif
