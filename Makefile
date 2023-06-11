# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:14:20 by nsion             #+#    #+#              #
#    Updated: 2023/06/11 13:56:59 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c mini_lib/lst.c mini_lib/ft_split.c mini_lib/utils.c instruction/s_.c instruction/p_.c instruction/r_.c instruction/rr_.c ft_printf/ft_printf.c  ft_printf/ft_find.c

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
