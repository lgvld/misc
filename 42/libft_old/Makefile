# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgavalda <lgavalda@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/11 09:06:46 by lgavalda          #+#    #+#              #
#    Updated: 2018/06/12 15:36:48 by lgavalda         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

DIR_SRC = ./

SRC = ft_memalloc.c \
ft_memset.c \
ft_power.c \
ft_putchar.c \
ft_putnbr.c \
ft_putstr.c \
ft_strlen.c

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(addprefix $(DIR_SRC), $(SRC))
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
