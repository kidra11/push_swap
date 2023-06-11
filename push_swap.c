/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 15:54:52 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	creat_array(t_stack **a, char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
		ps_atoi(argv[i++]);
	i = 0;
	while (i < argc)
	{
		ps_lstadd_back(a, ps_lstnew(ps_atoi(argv[i])));
		i++;
	}
}

void	check_dual(t_stack *lst)
{
	t_stack	*end;
	t_stack	*check;
	t_stack	*tmp;

	if (!lst)
		exit(ft_printf("Error: list failed to create.\n"));
	tmp = lst;
	while (tmp)
	{
		check = tmp;
		end = tmp->next;
		while (end)
		{
			if (check->nb == end->nb)
			{
				ps_lstclear(&lst);
				exit(ft_printf("Error: dual number detect.\n"));
			}
			end = end->next;
		}
		tmp = tmp->next;
	}
}

void	spliting(char **tab, t_stack *a, int choice)
{
	char	**check;
	int		i;

	i = 0;
	if (choice == 1)
		check = ft_split(tab[0], ' ');
	if (choice == 2)
		check = tab;
	while (check[i])
		i++;
	if (i <= 1)
		exit (0);
	else
	{
		creat_array(&a, check, i);
		check_dual(a);
	}
}

int	*sort_array(t_stack *lst)
{
	size_t	i;
	int		*arr;

	i = 0;
	arr = (int *)malloc(sizeof(int) * (ft_lstsize(lst)));
	while (lst)
	{
		arr[i] = lst->nb;
		lst = lst->next;
		i++;
	}
	bubble_sort(arr, i);
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_data	data;
	int		*array;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [list of integers]\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (argc < 3)
		spliting(argv + 1, a, 1);
	if (argc >= 3)
		spliting(argv + 1, a, 2);
	array = sort_array(a);
	sort(&a, &b, array, &data);
	ps_lstclear(&a);
	ps_lstclear(&b);
	free(array);
	return (0);
}
