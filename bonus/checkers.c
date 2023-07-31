/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 09:23:19 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 11:04:45 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	is_sorted_bn(t_stack *a, t_stack *b)
{
	if (b)
		return (1);
	while (a)
	{
		if (a->next && a->nb > a->next->nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	instructs(char *s, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(s, "sa\n"))
		b_swap(*a);
	else if (!ft_strcmp(s, "sb\n"))
		b_swap(*b);
	else if (!ft_strcmp(s, "ss\n"))
		return ((void)(b_swap(*a), b_swap(*b)));
	else if (!ft_strcmp(s, "pa\n"))
		b_push(b, a);
	else if (!ft_strcmp(s, "pb\n"))
		b_push(a, b);
	else if (!ft_strcmp(s, "ra\n"))
		b_rotate(a);
	else if (!ft_strcmp(s, "rb\n"))
		b_rotate(b);
	else if (!ft_strcmp(s, "rr\n"))
		return ((void)(b_rotate(a), b_rotate(b)));
	else if (!ft_strcmp(s, "rra\n"))
		b_reverse_rotate(a);
	else if (!ft_strcmp(s, "rrb\n"))
		b_reverse_rotate(b);
	else if (!ft_strcmp(s, "rrr\n"))
		return ((void)(b_reverse_rotate(a), b_reverse_rotate(b)));
	else
		return ((void)b_washing(a, b, s), exit(2));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [list of integers]\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (argc < 3)
		spliting(argv + 1, &a, 1);
	if (argc >= 3)
		spliting(argv + 1, &a, 2);
	str = get_next_line(0);
	while (str)
	{
		instructs(str, &a, &b);
		free(str);
		str = get_next_line(0);
	}
	return (b_washing(&a, &b, str));
}
