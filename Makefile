# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:15:39 by llaurent          #+#    #+#              #
#    Updated: 2019/11/21 17:52:58 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCSC		= srcs/ft_handlers.c\
				srcs/ft_printf.c\
				srcs/ft_strjoin_c.c

SRCSH		= includes/printf.h

OBJS		= $(SRCSC:%.c=%.o)

LIBFT		= libft/libft.a

NAME		= libftprintf.a

CC			= gcc

AR			= ar rc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS} libft
			${AR} ${NAME} ${OBJS} ${SRCSH} ${LIBFT}

libft:
			make -C libft all

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

test-a:		all
			${CC} ${NAME} ${LIBFT} main.c -o printf
			./printf a

test:		all
			${CC} ${NAME} ${LIBFT} main.c -o printf
			./printf

.PHONY:		all clean fclean re