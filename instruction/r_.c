/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:37:29 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 13:17:26 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack		*tmp;

	if (!(*a) || !(*a)->next)
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

	if (!(*b) || !(*b)->next)
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
