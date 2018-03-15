# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpetre <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/09 15:35:28 by cpetre            #+#    #+#              #
#    Updated: 2018/01/18 17:31:31 by mabanciu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
SRC			= *.c

OBJ			= $(SRC:%.c=%.o)
CFLAGS		= -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC)
	gcc $(CFLAGS) -c $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
