# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:16:35 by ide-dieg          #+#    #+#              #
#    Updated: 2024/12/08 00:55:22 by ide-dieg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = dia7

NAME2 = dia7_parte2

CC = cc

CFLAGS = -Wall -Wextra -Werror

LIBFT = libft.a

LIBFT_PATH = ../42_Libft

SRC = dia7.c

SRC2 = dia7_parte2.c

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