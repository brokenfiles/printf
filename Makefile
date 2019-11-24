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

SRCSC		= 	libft/ft_atoi.c\
				libft/ft_bzero.c\
				libft/ft_isdigit.c\
				libft/ft_strchr.c\
				libft/ft_strlen.c\
				srcs/ft_handlers.c\
				srcs/ft_handlers_2.c\
				srcs/ft_printf.c\
				srcs/ft_strjoin_c.c\
				srcs/handler_c.c\
				srcs/handler_diu.c\
				srcs/handler_o.c\
				srcs/handler_pxX.c\
				srcs/handler_s.c\
				srcs/handler_struct.c\
				srcs/handler_utils.c\
				libft/ft_strdup.c
SRCSH		= includes/printf.h
OBJS		= $(SRCSC:%.c=%.o)
NAME		= libftprintf.a
CC			= gcc
AR			= ar rc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

$(NAME):	${OBJS}
			@echo "\033[1;32m"
			@head -4 header
			@${AR} ${NAME} ${OBJS} ${SRCSH}

all:		${NAME}

clean:
			@echo "Deleting .o files.."
			@${RM} ${OBJS}

fclean:		clean
			@echo "Deleting binary files.."
			@${RM} ${NAME}

re:			fclean all

test-a:		all
			@${CC} ${NAME} ${LIBFT} main.c -o printf
			make clean
			./printf a

test:		all
			@${CC} ${NAME} ${CFLAGS} ${LIBFT} main.c -o printf
			make clean
			./printf

.PHONY:		all clean fclean re