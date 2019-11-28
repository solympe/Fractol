# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: solympe <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 17:17:21 by solympe           #+#    #+#              #
#    Updated: 2019/10/31 17:17:25 by solympe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c fractol_filler.c key_press.c
OBJ = main.o fractol_filler.o key_press.o

HEADER = fractol.h

$(NAME): $(OBJ)
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit

%.o:%.c $(HEADER)
	@gcc -Wall -Wextra -Werror -I . -c $< -o $@

clean:
	@/bin/rm -f *~
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

all: $(NAME)

re: fclean all

.PHONY: clean fclean all re
