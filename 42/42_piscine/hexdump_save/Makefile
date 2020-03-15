NAME = ft_hexdump

SRCS = ft_hexdump.c
SRCS += ft_hexdump2.c
SRCS += lib/ft_memcpy.c
SRCS += lib/ft_putstr.c
SRCS += lib/ft_strlen.c
SRCS += lib/ft_strncmp.c

OBJECTS = ${SRCS:.c=.o}

HEADERS_FOLDER = includes

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I${HEADERS_FOLDER} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJECTS}
	gcc ${CFLAGS} ${OBJECTS} -o ${NAME}

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f ${NAME}

re: fclean all
