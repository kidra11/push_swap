/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:54:45 by nsion             #+#    #+#             */
/*   Updated: 2023/05/01 10:54:48 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_stack
{
	int		*stack;
	int		size;
}				t_stack;

void	sa(t_stack *a);

void	sb(t_stack *b);

void	ss(t_stack *a, t_stack *b);

void	pa(t_stack *a, t_stack *b);

void	pb(t_stack *a, t_stack *b);

void	ra(t_stack *a);

void	rb(t_stack *b);

void	rr(t_stack *a, t_stack *b);

void	rra(t_stack *a);

void	rrb(t_stack *b);

void	rrr(t_stack *a, t_stack *b);

#endif