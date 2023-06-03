/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:07 by nsion             #+#    #+#             */
/*   Updated: 2023/06/03 20:34:42 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	int	tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
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
	ft_printf("ra\n");
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
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
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
	ft_printf("rra\n");
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
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
