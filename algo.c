/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:24:20 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 15:28:15 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	from_a_to_b(t_stack **a, t_stack **b, int *array, t_data *data)
{
	while (*a)
	{
		if (ft_lstsize(*a) == 1)
			push(a, b, 'b');
		while (ft_lstsize(*b) < data->end - data->start)
		{
			if (!((*a)->nb < array[data->end] && (*a)->nb >= array[data->start]))
				rotate(a, 'a');
			else
			{
				push(a, b, 'b');
				if ((*b)->nb < array[data->median])
					rotate(b, 'b');
			}
		}
		data->start -= data->size;
		if (data->start < 0)
			data->start = 0;
		data->end += data->size;
		if (data->end >= data->t_num)
			data->end = data->t_num - 1;
	}
}

void	from_b_to_a(t_stack **a, t_stack **b, int *array, t_data *data)
{
	data->unorder_num = 0;
	data->max = ft_lstsize(*b) - 1;
	while (*b)
	{
		if ((*b) && find_big_num(*b) == array[data->max])
			check_cases(a, b, array, data);
		else
			check_case2(a, data);
	}
	while (data->unorder_num != 0)
	{
		reverse_rotate(a, 'a');
		data->unorder_num--;
	}
}

void	check_cases(t_stack **a, t_stack **b, int *array, t_data *data)
{
	if ((*b)->nb == array[data->max])
	{
		push(b, a, 'a');
		data->max--;
		if ((*a)->next && (*a)->nb > (*a)->next->nb)
		{
			swap(*a, 'a');
			data->max--;
		}
	}
	else if ((*b)->nb == array[data->max - 1])
		push(b, a, 'a');
	else
		not_max_num(a, b, data);
}

void	check_case2(t_stack **a, t_data *data)
{
	if (data->unorder_num > 0)
	{
		reverse_rotate(a, 'a');
		data->unorder_num--;
		data->max--;
	}
}

void	not_max_num(t_stack **a, t_stack **b, t_data *data)
{
	if (data->unorder_num == 0 || (*b)->nb > ps_lstlast(*a)->nb)
	{
		push(b, a, 'a');
		rotate(a, 'a');
		data->unorder_num++;
	}
	else
	{
		if (find_big_num_index(*b, find_big_num(*b)) < ft_lstsize(*b) / 2)
			rotate(b, 'b');
		else
			reverse_rotate(b, 'b');
	}
}