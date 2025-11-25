# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/20 10:50:57 by jodone            #+#    #+#              #
#    Updated: 2025/11/25 15:16:29 by jodone           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
NAME=push_swap

SRC_DIR= src/

SRC= $(SRC_DIR)main.c \
	$(SRC_DIR)psh_lstnew.c \
	$(SRC_DIR)psh_lstadd_back.c \
	$(SRC_DIR)psh_lstlast.c \
	$(SRC_DIR)basic_instructions.c \
	$(SRC_DIR)both_instructions.c \
	$(SRC_DIR)sort_three.c \
	$(SRC_DIR)check_sort.c \
	$(SRC_DIR)sort.c

INCLUDES=-I push_swap.h \
		-I Great_Libft/Libft \
		-I Great_Libft/ft_printf \
		-I Great_Libft/GNL \

OBJECT=$(SRC:.c=.o)
LIBFT= ./Great_Libft/g_libft.a
CFLAGS=-Wall -Wextra -Werror -g 

all: $(NAME)

$(NAME): $(OBJECT) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJECT) $(LIBFT) -o $(NAME)

$(LIBFT):
		@$(MAKE) -C Great_Libft

%.o: %.c
		@$(CC) $(CFLAGS) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJECT)
		@$(MAKE) -C Great_Libft clean

fclean: clean
		@rm -f $(NAME)
		@$(MAKE) -C Great_Libft fclean
		
re: fclean all

.PHONY: all clean fclean re bonus