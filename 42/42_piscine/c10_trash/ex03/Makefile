NAME = ft_hexdump

SRCS = ft_hexdump.c
# SRCS += ft_hexdump2.c
# SRCS += lib/ft.c

OBJECTS = ${SRCS:.c=.o}

INCLUDES = includes

# CF`LAGS = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJECTS}
	gcc ${CFLAGS} ${OBJECTS} -o ${NAME}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${NAME}

re: fclean all
