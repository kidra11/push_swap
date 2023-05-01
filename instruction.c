/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:07:07 by nsion             #+#    #+#             */
/*   Updated: 2023/05/01 11:07:11 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int		tmp;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		a->stack[0] = a->stack[1];
		a->stack[1] = tmp;
	}
}

void	sb(t_stack *b)
{
	int		tmp;

	if (b->size > 1)
	{
		tmp = b->stack[0];
		b->stack[0] = b->stack[1];
		b->stack[1] = tmp;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	if (b->size > 0)
	{
		tmp = b->stack[0];
		i = 0;
		while (i < b->size - 1)
		{
			b->stack[i] = b->stack[i + 1];
			i++;
		}
		b->size--;
		i = a->size;
		while (i > 0)
		{
			a->stack[i] = a->stack[i - 1];
			i--;
		}
		a->stack[0] = tmp;
		a->size++;
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int		tmp;
	int		i;

	if (a->size > 0)
	{
		tmp = a->stack[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->size--;
		i = b->size;
		while (i > 0)
		{
			b->stack[i] = b->stack[i - 1];
			i--;
		}
		b->stack[0] = tmp;
		b->size++;
	}
}

void	ra(t_stack *a)
{
	int		tmp;
	int		i;

	if (a->size > 1)
	{
		tmp = a->stack[0];
		i = 0;
		while (i < a->size - 1)
		{
			a->stack[i] = a->stack[i + 1];
			i++;
		}
		a->stack[a->size - 1] = tmp;
	}
}

void	rb(t_stack *b)
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

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack *a)
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

void	rrb(t_stack *b)
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

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}