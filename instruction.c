/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:07 by nsion             #+#    #+#             */
/*   Updated: 2023/06/02 19:01:55 by nsion            ###   ########.fr       */
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
	
	if (!a || !(*a)->nb)
		return ;
	ps_lstadd_back(a, ps_lstnew((*a)->nb));
	tmp = (*a);
	(*a) = (*a)->next;
	free(tmp);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!b || !(*b)->nb)
		return ;
	ps_lstadd_back(b, ps_lstnew((*b)->nb));
	tmp = (*b);
	(*b) = (*b)->next;
	free(tmp);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	t_stack	*end;
	t_stack	*tmp;

	if (!a || !(*a)->nb)
		return ;
	tmp = (*a);
	end = ps_lstlast(*a);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	ps_lstadd_front(a, ps_lstnew(end->nb));
	free(end);
}

void	rrb(t_stack **b)
{
	t_stack	*end;
	t_stack	*tmp;

	if (!b || !(*b)->nb)
		return ;
	tmp = (*b);
	end = ps_lstlast(*b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	ps_lstadd_front(b, ps_lstnew(end->nb));
	free(end);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}