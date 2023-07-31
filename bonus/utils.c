/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 11:00:51 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 13:25:58 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	spliting(char **tab, t_stack **a, int choice)
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
		creat_array(a, check, i);
		check_dual(*a);
		if (is_sorted(*a) == 0)
		{
			ps_lstclear(a);
			exit(0);
		}
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
