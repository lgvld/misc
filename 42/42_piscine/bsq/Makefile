NAME = bsq

SRCS += bsq.c
SRCS += io.c
SRCS += parser.c
SRCS += checks.c

OBJ = ${SRCS:.c=.o}

INCLUDES = .

CFLAGS = -Wall -Wextra -Werror

.c.o:
	gcc ${CFLAGS} -I${INCLUDES} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	gcc ${CFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ${NAME}

re: fclean all
