# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 16:56:55 by ide-dieg          #+#    #+#              #
#    Updated: 2024/12/03 00:57:08 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dia2

NAME2 = dia2_parte2

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_PATH = ../42_Libft

SRC = dia2.c

SRC2 = dia2_parte2.c

build: build_libft
	$(CC) $(CFLAGS) -o $(NAME) $(NAME).c $(LIBFT_PATH)/$(LIBFT)

build2: build_libft
	$(CC) $(CFLAGS) -o $(NAME2) $(NAME2).c $(LIBFT_PATH)/$(LIBFT)

build_libft:
	make all -C $(LIBFT_PATH)

clean:
	rm -f $(NAME)
	rm -f $(NAME2)
	make clean -C $(LIBFT_PATH)

re: clean build

re2: clean build2