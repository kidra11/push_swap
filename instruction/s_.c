/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:35:41 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:36:07 by nsion            ###   ########.fr       */
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
