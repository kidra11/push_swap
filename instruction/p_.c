/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:36:24 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 11:06:30 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
