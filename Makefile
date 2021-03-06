#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: etugoluk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/16 10:20:10 by etugoluk          #+#    #+#              #
#    Updated: 2018/07/16 10:20:11 by etugoluk         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

SRCS = main.c \
		codes.c \
		add_fractols.c \
		draw.c \

LIB = -L libft/ -lft
OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

libft: 
	make -C ./libft

$(NAME): libft $(OBJ)
	gcc $(CFLAGS) -g $(OBJ) -lpthread -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIB) -I ./

clean:
	/bin/rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft fclean

re: fclean all

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $< -I libft/

.PHONY: all clean fclean re libft

.NOTPARALLEL: all clean fclean re libft