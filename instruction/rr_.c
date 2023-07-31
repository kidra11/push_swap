/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:37:59 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 13:17:36 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a)
{
	t_stack	*end;
	t_stack	*tmp;

	if (!a || !(*a)->next)
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

	if (!b || !(*b)->next)
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
