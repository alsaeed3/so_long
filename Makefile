# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 09:55:28 by alsaeed           #+#    #+#              #
#    Updated: 2023/09/01 11:20:55 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	src/free_exit_utils.c src/keyboard_hooks.c src/print_map.c src/utils.c \
		src/utils2.c src/valid_path.c src/main.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INC = -Imlx

$(NAME): libft/libft.a ${OBJS}
		@make -C MLX
		@cp ./mlx/libmlx.a .
		$(CC) $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME)

%.o: %.c
	${CC} ${CFLAGS} ${INC} -c $< -o $@

all: libft $(NAME)


libft:
		@make -C libft

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

.PHONY: all libft clean fclean re