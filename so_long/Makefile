# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 09:55:28 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/06 10:53:53 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	src/free_exit_utils.c src/move_utils.c src/print_map.c src/map_utils.c \
		src/img_utils.c src/find_valid_path.c src/main.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -Imlx
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(MLX_LIB) $(LIBFT_LIB) $(NAME)

.c.o:
	${CC} ${CFLAGS} -c $< -o $@ ${INC}


$(NAME): ${OBJS}
		@make -C MLX
		@cp ./mlx/libmlx.a .
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB)
		
$(MLX_LIB):
	@make -C $(MLX_DIR)
	
$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

clean: 
		@rm -f $(OBJS)
		@$(RM) $(NAME).dSYM
		@make clean -C libft
		@make clean -C mlx

fclean: clean
		@rm -f $(NAME)
		@rm -f libmlx.a
		@make fclean -C libft

re: fclean all 

.PHONY: all clean fclean re