CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
AR = ar rcs
SRCS = ft_print_addresse.c \
		ft_print_lowhexa.c \
		ft_print_upperhexa.c \
		ft_printf.c \
		ft_putchar.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_uputnbr.c \
		printf_spec.c \
		ft_strchr.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
		 
