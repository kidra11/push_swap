/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:07 by nsion             #+#    #+#             */
/*   Updated: 2023/05/29 18:26:20 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int tmp;

	if (!*a || !(*a)->next)
		return 	;
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp; 
}

void	sb(t_stack **b)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return 	;
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp; 
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	ps_lstadd_front(a, ps_lstnew((*b)->nb));
	tmp = (*b);
	(*b) = (*b)->next;
	free(tmp);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack		*tmp;

	if (!*a)
		return ;
	ps_lstadd_front(b, ps_lstnew((*a)->nb));
	tmp = (*a);
	(*a) = (*a)->next;
	free(tmp);
}

void	ra(t_stack **a)
{
	t_stack		*tmp;
	
	if (!a)
		return ;
	tmp = (*a);
	ps_lstlast(a);
	
	free(tmp);
}

/* void	rb(t_stack **b)
{
	int		tmp;
	int		i;

	if (b->size > 1)
	{
		tmp = b->stack[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->stack[b->size - 1] = tmp;
	}
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	int		tmp;
	int		i;

	if (a->size > 1)
	{
		tmp = a->stack[a->size - 1];
		i = a->size - 1;
		while (i > 0)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[0] = tmp;
	}
}

void	rrb(t_stack **b)
{
	int		tmp;
	int		i;

	if (b->size > 1)
	{
		tmp = b->stack[b->size - 1];
		i = b->size - 1;
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = tmp;
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}*/