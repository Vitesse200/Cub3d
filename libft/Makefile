# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpons <mpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 14:25:48 by mpons             #+#    #+#              #
#    Updated: 2022/05/02 13:50:31 by mpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c\
			  ft_isdigit.c\
			  ft_isalnum.c\
			  ft_isascii.c\
			  ft_isprint.c\
			  ft_strlen.c\
			  ft_memset.c\
			  ft_bzero.c\
			  ft_memcpy.c\
			  ft_memmove.c\
			  ft_strlcpy.c\
			  ft_strlcat.c\
			  ft_toupper.c\
			  ft_tolower.c\
			  ft_strchr.c\
			  ft_strrchr.c\
			  ft_strncmp.c\
				ft_strcmp.c\
			  ft_memchr.c\
			  ft_memcmp.c\
			  ft_strnstr.c\
			  ft_atoi.c\
			  ft_calloc.c\
			  ft_strdup.c\
			  ft_substr.c\
			  ft_strjoin.c\
			  ft_strtrim.c\
			  ft_split.c\
			  ft_itoa.c\
			  ft_strmapi.c\
			  ft_striteri.c\
			  ft_putchar_fd.c\
			  ft_putstr_fd.c\
			  ft_putendl_fd.c\
			  ft_putnbr_fd.c\

BONUS		= ft_lstnew.c\
			  ft_lstadd_front.c\
			  ft_lstsize.c\
			  ft_lstlast.c\
			  ft_lstadd_back.c\
			  ft_lstdelone.c\
			  ft_lstclear.c\
			  ft_lstiter.c\
			  ft_lstmap.c\

OBJS		= ${SRCS:.c=.o}

B_OBJS		= ${BONUS:.c=.o}

NAME 		= libft.a

CC 			= gcc
CFLAGS		= -g3 -Wall -Wextra -Werror 

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

RM			= rm -f

LIB			= ar rc 

RAN			= ranlib

all:		${NAME}

${NAME}: 	${OBJS}
		 	${LIB} ${NAME} ${OBJS}
			${RAN} ${NAME}

bonus:		${OBJS} ${B_OBJS}
		 	${LIB} ${NAME} ${OBJS} ${B_OBJS}
			${RAN} ${NAME}

clean:
			${RM} ${OBJS} ${B_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
