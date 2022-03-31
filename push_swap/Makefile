# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hzona <hzona@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 16:12:07 by hzona             #+#    #+#              #
#    Updated: 2021/11/03 12:15:07 by hzona            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

SRC = arrforcheck.c commands.c commands_reverse.c ft_atoi.c ft_split.c lstutils.c main.c push_swap.c small_sort.c sort_utils.c stack_distribute.c start_sort.c strutils.c add_main.c

SRC_BONUS = arrforcheck.c checker.c commands.c commands_reverse.c ft_atoi.c ft_split.c lstutils.c main.c push_swap.c small_sort.c sort_utils.c stack_distribute.c start_sort.c strutils.c

SRCS_DIR = Mandatory/

SRCS_DIR_BONUS = Bonus/

OBJS = ${addprefix ${SRCS_DIR}, ${SRC:.c=.o}}

BONUS_OBJS = ${addprefix ${SRCS_DIR_BONUS}, ${SRC_BONUS:.c=.o}}

HEADER = push_swap.h

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

.PHONY: all clean fclean re bonus

%.o:%.c		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${HEADER}
			@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
			@echo "push_swap compiled successfully!"

bonus:		${NAME_BONUS}

${NAME_BONUS}:			${BONUS_OBJS} ${HEADER}
						@${CC} ${CFLAGS} -o ${NAME_BONUS} ${BONUS_OBJS}
						@echo "checker compiled successfully!"

all:		${NAME} ${NAME_BONUS}

fclean:		
			@${RM} ${OBJS} ${BONUS_OBJS} ${NAME} ${NAME_BONUS}
			@echo "fclean successfully!"

clean:		
			@${RM} ${OBJS} ${BONUS_OBJS} 
			@echo "fclean successfully!"

re: fclean all