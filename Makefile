# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 16:49:53 by azaher            #+#    #+#              #
#    Updated: 2023/11/17 15:13:35 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c \
	   src/engine/engine_start.c \
	   src/engine/engine_tools.c \
	   src/engine/graphics_tools.c \
	   src/engine/raycasting.c
CFLAGS= -Wall -Wextra -Werror -O3  -I ./libraries/libft -fsanitize=address -g
FLAGS = -L ./libraries/minilibx -lmlx -lm -lX11 -lXext ${LIBFT}
#-framework opengl ${LIBFT} ${LIBMLX} -framework Appkit
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
	rm -f $(OBJ)  

fclean : clean
	make -C ./libraries/libft fclean
	rm -f $(NAME)
	rm -f $(OBJ)  

re : fclean all