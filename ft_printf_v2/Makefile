# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jereligi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/19 16:29:40 by jereligi          #+#    #+#              #
#    Updated: 2019/11/22 11:05:02 by jereligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH = ./srcs/

SRCS =	ft_printf.c \
		ft_utils.c \
		ft_check_set.c \
		ft_strjoin.c \
		ft_flags_management.c \
		ft_flags_management_integer.c \
		ft_display_management.c \
		ft_get_strlen.c \
		ft_exception_flag.c \
		ft_itoa.c \
		ft_unsigned_itoa.c \
		ft_atoi.c

_SRC = $(addprefix $(PATH), $(SRCS))

OBJ = $(_SRC:.c=.o)

INCLUDES = ./includes

CC = gcc

##CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDES)
	ar rc $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
