# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/24 11:18:32 by lgavalda          #+#    #+#              #
#    Updated: 2019/07/24 11:42:41 by lgavalda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op

SRCS += do_op.c
SRCS += ft_op.c
SRCS += io.c

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
