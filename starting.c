/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:46:15 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 15:54:47 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stack **a)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb
		&& (*a)->nb < (*a)->next->next->nb)
		sa(a);
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb < (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
		ra(a);
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb < (*a)->next->next->nb)
	{
		sa(a);
		ra(a);
	}
	else if ((*a)->nb > (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
	{
		ra(a);
		sa(a);
	}
	else if ((*a)->nb < (*a)->next->nb && (*a)->next->nb > (*a)->next->next->nb
		&& (*a)->nb > (*a)->next->next->nb)
		rra(a);
}

void	five(t_stack **a, t_stack **b)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(*a);
	if (ft_lstsize(*a) == 5)
		aftersmallnum = find_after_smallnum(*a);
	else
		aftersmallnum = smallnum;
	while (ft_lstsize(*a) > 3)
	{
		if ((*a)->nb == smallnum || (*a)->nb == aftersmallnum)
			pb(a, b);
		else
			ra(a);
	}
	three(a);
	if ((*b)->next && (*b)->nb < (*b)->next->nb)
		sb(b);
	while (*b)
		pa(a, b);
}

void	sort(t_stack **a, t_stack **b, int *array, t_data *data)
{
	if (ft_lstsize(*a) <= 3)
		three(a);
	else if (ft_lstsize(*a) <= 5)
		five(a, b);
	else
	{
		data->t_num = ft_lstsize(*a);
		data->median = (data->t_num / 2);
		if (data->t_num <= 30)
			data->n = 5;
		else if (data->t_num <= 150)
			data->n = 8;
		else
			data->n = 18;
		data->size = (data->t_num / data->n);
		data->start = data->median - data->size;
		data->end = data->median + data->size;
		from_a_to_b(a, b, array, data);
		from_b_to_a(a, b, array, data);
	}
}

