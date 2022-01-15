# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlinares <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 15:20:51 by rlinares          #+#    #+#              #
#    Updated: 2020/11/12 15:33:55 by rlinares         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RCS	= ${./srcs/cat.c}
OBJS	= ${SRCS:.c=.o}
	INCL	= includes
	CC		= gcc
	CFLAGS	= -Wall -Wextra -Werror
	NAME	= ft_cat

.c.o	:	
				${CC} -I ${INCL} ${CFLAGS} -c $< -o ${<:.c=.o}
all		:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}

${NAME}	:	all

clean	:
				rm -f ${OBJS}
fclean	:	clean
				rm -f ${NAME}
re		:	fclean all
