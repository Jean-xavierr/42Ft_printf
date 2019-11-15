/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:42:21 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/15 15:32:21 by jereligi         ###   ########.fr       */
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
	char		precision;
	int			precision_nb;
	int			return_printf;
}					t_data;

// ---> ft_printf.c <---
int					ft_check_string(int i, t_data *data);
int					ft_print(const char *s, ...);

// ---> ft_utils.c <---
void				ft_putchar(char c, t_data *data);
int					ft_strlen(char *s);
void				ft_reinit_flags(t_data *data);
void				ft_init(const char *s, t_data *data);

// ---> ft_check_set.c <---
int					ft_is_char(char c);
int					ft_check_set(char c);

// ---> ft_strjoin.c <--
char				*ft_strjoin(char *s1, char *s2);

#endif
