/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 15:38:09 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 15:53:03 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int arr_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < arr_len)
	{
		j = 0;
		while (j < arr_len)
		{	
			if ((j + 1 < arr_len) && arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_big_num(t_stack *lst)
{
	int	bignum;

	bignum = lst->nb;
	lst = lst->next;
	while (lst)
	{
		if (lst->nb > bignum)
			bignum = lst->nb;
		lst = lst->next;
	}
	return (bignum);
}

int	find_small_num(t_stack *lst_a)
{
	int	smallnum;

	smallnum = lst_a->nb;
	lst_a = lst_a->next;
	while (lst_a)
	{
		if (lst_a->nb < smallnum)
			smallnum = lst_a->nb;
		lst_a = lst_a->next;
	}
	return (smallnum);
}

int	find_after_smallnum(t_stack *lst_a)
{
	int	smallnum;
	int	aftersmallnum;

	smallnum = find_small_num(lst_a);
	if (lst_a->nb == smallnum)
		lst_a = lst_a->next;
	aftersmallnum = lst_a->nb;
	lst_a = lst_a->next;
	while (lst_a)
	{
		if (lst_a->nb < aftersmallnum && lst_a->nb != smallnum)
			aftersmallnum = lst_a->nb;
		lst_a = lst_a->next;
	}
	return (aftersmallnum);
}

int	find_big_num_index(t_stack *lst, int max)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->nb == max)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}