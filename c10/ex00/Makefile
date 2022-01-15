# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 15:20:06 by rlinares          #+#    #+#              #
#    Updated: 2020/11/12 15:20:21 by rlinares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RCS	= srcs/main.c
OBJS	= ${SRCS:.c=.o}
	CC		= gcc
	CFLAGS	= -Wall -Werror -Wextra
	NAME	= ft_display_file

.c.o	:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all		:	${OBJS}
				${CC} -o ${NAME} ${OBJS}
${NAME}	:	all
	clean	:
				rm -f ${OBJS}
fclean	:	clean
				rm -f ${NAMiE}
