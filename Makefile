# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 09:55:28 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/04 13:18:44 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	src/free_exit_utils.c src/keyboard_hooks.c src/print_map.c src/utils.c \
		src/utils2.c src/valid_path.c src/main.c
OBJ	= $(SRC:.c=.o)

(CC) = cc
INCLUDES = -I/usr/include -Imlx_linux -Ilibft/inc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -L./mlx_linux -lmlx_Linux -L/usr/lib/X11 -lXext -lX11
NAME = so_long

MLX_DIR = ./mlx_linux
MLX_LIB = $(MLX_DIR)/libmlx_Linux.a

.c.o:
	$(CC) $(CFLAGS) -D BUFFER_SIZE=1 -c $< -o $@ $(INCLUDES)

$(NAME): $(OBJ)
		$(MAKE) -C libft
		$(MAKE) -C mlx_linux
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS) libft/libft.a

all:	$(NAME)

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C mlx_linux

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re