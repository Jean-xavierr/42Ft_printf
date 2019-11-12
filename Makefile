NAME = libftprintf.a

PATH = ./srcs/

SRCS =	ft_printf.c \
		ft_print_utils.c \
		ft_print_type_c.c \
		ft_print_type_integer.c \
		ft_print_type_s.c \
		ft_print_type_p.c \
		ft_print_type_convert_hex.c \
		ft_putstr.c 

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
