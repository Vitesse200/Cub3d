# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgaillar <lgaillar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:52:35 by jhermon-          #+#    #+#              #
#    Updated: 2022/08/26 15:48:23 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub3d.c\
			error.c\
			open_map.c\
			extract_map.c\
			extract_map_support.c\
			check_0_map.c\
			check_0_map_2.c\
			check_data_map.c\
			check_data_support.c\
			check_data_hexa.c\
			window.c\
			support.c\
      		image_generator.c\
      		draw_map.c\
			hooks.c\
			hooks_move.c\
			texture_extract.c\
			texture_init.c\
           	raycasting.c\
           	free.c\
           	gnl.c\
           	gnl_utils.c\
           	raycasting_2.c\


CC = gcc -g

NAME = cub3D

OBJ = $(SRC:.c=.o)
	
FLAGS = -Imlx -Wall -Wextra -Werror -Imlx -g -fsanitize=address

LIBX = -Lmlx -lmlx -lz -framework OpenGL -framework AppKit

LIBFT_DIR	= ./libft

LIBFT		= ./libft/libft.a 
all: $(NAME)

$(NAME): $(OBJ) 
			$(MAKE) -C $(LIBFT_DIR)
	    $(CC) $(FLAGS) $(LIBX) -o $(NAME) $(OBJ) $(LIB) $(LIBFT)

$(OBJ): $(SRC)
		$(CC) $(FLAGS) -c $(SRC)

exe: all
		./$(NAME) map.cub

norm: 
		norminette -d $(SRC) 

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
