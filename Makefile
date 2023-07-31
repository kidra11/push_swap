# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsion <nsion@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/01 11:14:20 by nsion             #+#    #+#              #
#    Updated: 2023/07/31 11:57:59 by nsion            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c algo_utils.c algo.c starting.c mini_lib/lst.c mini_lib/ft_split.c mini_lib/utils.c instruction/s_.c instruction/p_.c instruction/r_.c instruction/rr_.c ft_printf/ft_printf.c  ft_printf/ft_find.c

SRCS_BONUS = bonus/checkers.c bonus/instruction.c bonus/get_next_line.c bonus/get_next_line_utils.c bonus/utils.c algo_utils.c algo.c starting.c mini_lib/lst.c mini_lib/ft_split.c mini_lib/utils.c instruction/s_.c instruction/p_.c instruction/r_.c instruction/rr_.c ft_printf/ft_printf.c  ft_printf/ft_find.c

NAME = push_swap

BNAME = checker

GCC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

OBJS = $(SRCS:.c=.o)

BOBJS = $(SRCS_BONUS:.c=.o)

all	: $(NAME)

bonus : $(BNAME)

.c.o	:
	$(GCC) -I. -o $@ -c $? $(CFLAGS)

$(NAME)	: $(OBJS)
	$(GCC) $(OBJS) -o $(NAME)

$(BNAME) : $(BOBJS)
	$(GCC) $(BOBJS) -o $(BNAME)

clean	:
	$(RM) $(OBJS) $(BOBJS)

fclean	:	clean
	$(RM) $(NAME) $(BNAME)

re	: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

.PHONY	: all clean fclean re bonus
