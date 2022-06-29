# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/07 09:34:50 by halvarez          #+#    #+#              #
#    Updated: 2022/06/29 16:57:04 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME    	= hgenerator.out
BUF			= 2000
SRCS    	= get_next_line_bonus.c get_next_line_utils_bonus.c	files_managing.c \
	get_prototypes.c hgenerator.c hgen_utils_1.c main.c ft_split.c
OBJS		= ${SRCS:.c=.o}
BONUS_O		= ${BONUS_C:.c=.o}
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=${BUF}
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${SRCS}

all:    ${NAME}

clean:
		${RM} ${OBJS}
		${RM} ${BONUS_O}

fclean:    clean
		${RM} ${NAME}
        
re:     fclean all

.PHONY: all clean fclean re bonus
