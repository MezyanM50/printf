CC = cc
	CFLAGS = -Wall -Wextra -Werror
	NAME = libftprintf.a
SRC = ft_printf.c ft_printf_utils.c ft_printf_utils2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
