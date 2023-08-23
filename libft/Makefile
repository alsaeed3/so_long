# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alsaeed <alsaeed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/11 14:48:47 by alsaeed           #+#    #+#              #
#    Updated: 2023/08/15 10:40:22 by alsaeed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a

SRCS =			src/ft_isalpha.c src/ft_isdigit.c src/ft_isalnum.c src/ft_isascii.c src/ft_isprint.c \
				src/ft_memset.c src/ft_bzero.c src/ft_memcpy.c src/ft_memmove.c src/ft_strlcpy.c \
				src/ft_strlcat.c src/ft_toupper.c src/ft_tolower.c src/ft_strchr.c src/ft_strrchr.c \
				src/ft_strncmp.c src/ft_memchr.c src/ft_memcmp.c src/ft_strnstr.c src/ft_calloc.c \
				src/ft_strdup.c src/ft_atoi.c src/ft_substr.c src/ft_strjoin.c src/ft_strtrim.c \
				src/ft_split.c src/ft_itoa.c src/ft_strmapi.c src/ft_striteri.c src/ft_putchar_fd.c \
				src/ft_putstr_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c 
OBJS = 			$(SRCS:.c=.o)

SRCT =			src/ft_bzero.c src/ft_strchr.c src/ft_strdup.c src/ft_strtrim.c src/ft_memcpy.c \
				src/ft_memset.c src/ft_substr.c src/ft_calloc.c src/ft_strlcpy.c
OBJT =			$(SRCT:.c=.o)

SRC_LIST =  	src/ft_lstnew.c src/ft_lstadd_front.c src/ft_lstsize.c src/ft_lstlast.c \
				src/ft_lstadd_back.c src/ft_lstdelone.c src/ft_lstclear.c src/ft_lstiter.c \
				src/ft_lstmap.c 
OBJ_LIST = 		$(SRC_LIST:.c=.o)

SRC_PRINTF =	src/ft_putchar.c src/ft_putstr.c src/ft_putnbr.c src/print_hex.c \
				src/print_pointer.c src/print_undec.c src/ft_printf.c src/ft_atoi.c
OBJ_PRINTF =	$(SRC_PRINTF:.c=.o)

SRC_GNL =		src/get_next_line.c src/get_next_line_utils.c
OBJ_GNL =		$(SRC_GNL:.c=.o)

CC = 			cc
CFLAGS =		-Wall -Wextra -Werror -g3 -fsanitize=address
RM = 			rm -f
ARFLAGS = 		ar -rcs

all: 			$(NAME)

$(NAME): 		$(OBJT) $(OBJ_PRINTF) $(OBJ_GNL)
				@$(ARFLAGS) $(NAME) $(OBJT) $(OBJ_PRINTF) $(OBJ_GNL)

clean:
				@$(RM) $(OBJT) $(OBJ_PRINTF) $(OBJ_GNL)

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re