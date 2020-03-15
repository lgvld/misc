NAME = ft_cat

SRCS = ft_cat.c
SRCS += io.c

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
