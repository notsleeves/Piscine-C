# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msteak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/28 18:44:58 by msteak            #+#    #+#              #
#    Updated: 2021/02/28 18:45:00 by msteak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
SRCS	= main.c ft_atoi.c ft_read_map.c ft_map.c ft_find_sub_map.c ft_vectors.c
OBJS 	= ${SRCS:.c=.o}
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			${CC} ${OBJS} -o ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
