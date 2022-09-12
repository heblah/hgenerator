# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/12 10:58:00 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= hgenerator
SRCS_DIR	= ./src/
SRCS		= 00_main.c 01_define_header.c 02_files_managing.c 03_get_prototypes.c
OBJS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.o})
DEPS		= $(addprefix ${SRCS_DIR}, ${SRCS:.c=.d})
CC			= cc 
CFLAGS		= -Wall -Wextra -Werror -g -MMD -MP
CLIB		= -Llibft -lft
MAKE		= make
CLEAN		= make clean
FCLEAN		= make fclean
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${MAKE} -C libft
		${CC} ${OBJS} ${CLIB} -o ${NAME}

all:    ${NAME}

clean:
		${RM} ${OBJS} ${DEPS}
		${CLEAN} -C libft

fclean: clean
		${RM} ${NAME}
		${FCLEAN} -C libft

re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
