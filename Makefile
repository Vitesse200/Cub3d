# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 19:52:35 by jhermon-          #+#    #+#              #
#    Updated: 2022/06/05 15:31:25 by jhermon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = cub3d.c\
			error.c\
			get_next_line.c\
			open_map.c\
			exctract_map.c\
			check_map.c\
			new_check_map.c\
			new_check_holes.c\

CC = gcc

NAME = cub3D

OBJ = $(SRC:.c=.o)
	
FLAGS = -Wall -Wextra -Werror -Imlx

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
