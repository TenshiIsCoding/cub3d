# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 16:49:53 by azaher            #+#    #+#              #
#    Updated: 2023/10/19 11:48:21 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c \
	   src/engine/engine_start.c

CFLAGS= -Wall -Wextra -Werror -I ./libraries/libft
FLAGS = -framework opengl ${LIBFT} ${LIBMLX} -framework Appkit
NAME = cub3D
OBJ = $(SRCS:.c=.o)
LIBFT=libraries/libft/libft.a
LIBMLX=libraries/minilibx/libmlx.a


all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX)
	gcc $(OBJ) $(CFLAGS) $(FLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libraries/libft/

$(LIBMLX):
	make -C ./libraries/minilibx/

clean :
	make -C ./libraries/libft clean
	make -C  ./libraries/minilibx clean
	rm -rf ${LIBFT}
	rm -rf ${LIBMLX}

fclean : clean
	make -C ./libraries/libft fclean
	rm -f $(NAME)

re : fclean all