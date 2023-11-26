# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azaher <azaher@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 16:49:53 by azaher            #+#    #+#              #
#    Updated: 2023/10/31 17:14:36 by azaher           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c \
	   src/engine/engine_start.c \
	   src/parsing/parsing.c \
	   src/parsing/parse_info.c \
	   src/parsing/pars_utils.c \
	   src/parsing/check_file.c \
	   src/parsing/parse_map.c \
	   libraries/get_next_line/get_next_line.c \
	   libraries/get_next_line/get_next_line_utils.c 
 
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3
FLAGS = -L ./libraries/minilibx -lmlx -lm -lX11 -lXext ${LIBFT}
NAME = cub3D
OBJ = $(SRCS:.c=.o)
LIBFT=libraries/libft/libft.a
LIBMLX=libraries/minilibx/libmlx.a


all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT) $(LIBMLX)
	gcc $(OBJ) $(CFLAGS) $(FLAGS) -o $(NAME)

$(LIBFT):
	make -s -C ./libraries/libft/

$(LIBMLX):
	make -s -C ./libraries/minilibx/

clean :
	make -s -C ./libraries/libft clean
	make -s -C  ./libraries/minilibx clean
	rm -rf ${LIBFT}
	rm -rf ${LIBMLX}
	rm -f $(OBJ)  

fclean : clean
	make -C ./libraries/libft fclean
	rm -f $(NAME)
	rm -f $(OBJ)  

re : fclean all