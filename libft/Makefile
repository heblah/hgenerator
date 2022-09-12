# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: halvarez <halvarez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 16:55:50 by halvarez          #+#    #+#              #
#    Updated: 2022/09/12 11:25:52 by halvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    	= libft.a
LIBFT_DIR	= ./libft/
LIBFT		= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c
LIBFT		+=ft_isdigit.c ft_itoa.c ft_memcmp.c ft_memcpy.c ft_memmove.c
LIBFT		+=ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIBFT		+=ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c
LIBFT		+=ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_strncmp.c ft_strnstr.c
LIBFT		+=ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
PRINTF_DIR	+= ./printf/
PRINTF		= ft_printf.c ft_puthex.c ft_putnbr.c ft_puttxt.c
GNL_DIR		+= ./gnl/
GNL			= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS		= $(addprefix ${LIBFT_DIR}, ${LIBFT:.c=.o})
OBJS		+= $(addprefix ${PRINTF_DIR}, ${PRINTF:.c=.o})
OBJS		+= $(addprefix ${GNL_DIR}, ${GNL:.c=.o})
DEPS		= $(addprefix ${LIBFT_DIR}, ${LIBFT:.c=.d})
DEPS		+= $(addprefix ${PRINTF_DIR}, ${PRINTF:.c=.d})
DEPS		+= $(addprefix ${GNL_DIR}, ${GNL:.c=.d})
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -MMD -MP
RM			= rm -rf

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		ar -rcs ${NAME} ${OBJS}

all:    ${NAME}

clean:
		${RM} ${OBJS} ${DEPS}

fclean:    clean
		${RM} ${NAME}
        
re:     fclean all

-include ${DEPS}

.PHONY: all clean fclean re bonus
