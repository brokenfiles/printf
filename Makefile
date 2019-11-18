# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llaurent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 11:15:39 by llaurent          #+#    #+#              #
#    Updated: 2019/11/08 10:45:33 by llaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
PATH_SRCS = srcs
PATH_HEADERS = includes
PATH_LIBS = libs
COMPILER_COMMAND = gcc
LIB_CREATOR_COMMAND = ar
RM_COMMAND = rm -f
FLAGS = -Wall -Wextra -Werror
OPTIONS = -I${PATH_HEADERS}
SRCS = ${PATH_SRCS}/ft_printf.c
LIBS = ${PATH_LIBS}/ft_strlen.c
OBJS = ${SRCS:.c=.o}
LIBS_OBJS = ${LIBS:.c=.o}

all: ${NAME}

.c.o: ${OBJS} ${LIBS_OBJS}
	${COMPILER_COMMAND} ${OPTIONS} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS} ${LIBS_OBJS}
	${LIB_CREATOR_COMMAND} rc ${NAME} ${OBJS} ${LIBS_OBJS}

clean:
	${RM_COMMAND} ${OBJS} ${LIBS_OBJS}

fclean: clean
	${RM_COMMAND} ${NAME}

re: fclean all