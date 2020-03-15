NAME = libft.a

SRCS = srcs/ft_putchar.c
SRCS += srcs/ft_putstr.c
SRCS += srcs/ft_strcmp.c
SRCS += srcs/ft_strlen.c
SRCS += srcs/ft_swap.c

OBJ = ${SRCS:.c=.o}

INCLUDES = includes

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:	${OBJ}
	ar rc ${NAME} $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f libft.a

re:	fclean all
