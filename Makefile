# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:52:35 by jhermon-          #+#    #+#              #
#    Updated: 2022/07/20 15:57:57 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub3d.c\
			error.c\
			get_next_line.c\
			open_map.c\
			exctract_map.c\
			check_0_map.c\
			check_0_map_2.c\
			check_data_map.c\
			check_data_support.c\
			check_data_hexa.c\
			extract_map_support.c\
			window.c\
            Image_generator.c\
            Raycasting_finished_23_06_2022.c\
			hooks.c\
			hooks_move.c\
			texture_extract.c\
			texture_init.c\
           	raycasting.c\
           	free.c\
           	gnl.c\
           	gnl_utils.c\

CC = gcc -g

NAME = cub3D

OBJ = $(SRC:.c=.o)
	
FLAGS = -Imlx -Wall -Wextra -Werror -Imlx -g #-fsanitize=address

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

#norm: 
#		norminette -d so_long.c open_map.c check_map.c check_map_utils.c error.c get_next_line.c get_next_line_utils.c window.c print_map.c ft_itoa.c hooks.c draw_player.c so_long.h gnl.h

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
