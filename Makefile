# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 09:55:28 by alsaeed           #+#    #+#              #
#    Updated: 2023/08/18 14:58:47 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	src/read_map.c src/parse_map.c src/player_movement.c src/ft_exit.c \
		src/check_walls_pec.c src/check_valid_path.c src/so_long.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
INC = -I inc -I mlx
RM = rm -rf

.c.o:
	${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

all: libft $(NAME)

$(NAME): libft/libft.a ${OBJS}
		@make -C mlx all
		@cp ./mlx/libmlx.a .
		$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit libft/libft.a

libft:
		@make -C libft all

clean: 
		@${RM} *.o */*.o */*/*.o
		@$(RM) $(NAME).dSYM
		@make -C libft clean

fclean: clean
		@${RM} ${NAME}
		@${RM} libmlx.a
		@make -C libft fclean

re: fclean all 

.PHONY: all libft clean fclean re