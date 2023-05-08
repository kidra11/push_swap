# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:14:20 by nsion             #+#    #+#              #
#    Updated: 2023/05/08 14:05:33 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c mini_lib.c instruction.c 

NAME = push_swap

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

all	: $(NAME)

.c.o	:
	$(GCC) -I. -o $@ -c $? $(CFLAGS)

$(NAME)	: $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
