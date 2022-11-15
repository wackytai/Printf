NAME = libftprintf.a

C_SOURCES = ft_printf.c ft_putchar.c ft_putnbr_base.c \
			ft_strlen.c ft_tolower.c ft_toupper.c

OBJ = $(C_SOURCES:.c=o)

CREATE = @ar -rc

REMOVE = @rm -f

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
			$(CREATE) $(NAME) $(OBJ)

clean:
		$(REMOVE) *.o

fclean:	clean
		$(REMOVE) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re