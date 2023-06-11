/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:54:45 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:54:59 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/libftprintf.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}			t_stack;

//instruction
void	sa(t_stack **a);

void	sb(t_stack **b);

void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);

void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);

void	rb(t_stack **b);

void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);

void	rrb(t_stack **b);

void	rrr(t_stack **a, t_stack **b);

// mini_lib.c
void	ps_lstadd_back(t_stack **lst, t_stack *new);

void	ps_lstadd_front(t_stack **lst, t_stack *new);

t_stack	*ps_lstnew(int content);

int		ps_atoi(const char *nptr);

void	ps_lstclear(t_stack **lst);

t_stack	*ps_lstlast(t_stack *lst);

int		ft_strlen(const char *str);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		ft_isdigit(char c);

#endif