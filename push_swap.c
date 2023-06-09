/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/06/09 14:31:39 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	creat_array(t_stack **a, char **argv, int argc)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ps_lstadd_back(a, ps_lstnew(ps_atoi(argv[i])));
		i++;
	}
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->nb);
		stack = stack->next;
	}
	printf("\n");
}

void	check_dual(int num, t_stack *lst)
{
	t_stack *end;
	int	check;

	if (!num || !lst)
	{
		ft_printf("Error.\n");
		return ;
	}
	end = lst;
	check = lst->nb;
	while (end->next)
	{
		lst = lst->next;
		while (lst->next)
		{
			if (check == lst->nb)
				exit(ft_printf("Error: dual number detect.\n"));
			lst = lst->next;
		}
		end = end->next;
	}
}

void	spliting(char **tab, t_stack *a, int choice)
{
	char	**check;
	int		i;

	i = 0;
	if (choice == 1)
		check = ft_split(tab[1], ' ');
	if (choice == 2)
		check = tab;
	while (check[i])
		i++;
	if (choice == 2)
		i--;
	//ft_printf("tableau : %d\n", i);
	if (i <= 1)
		exit(ft_printf("Error : you must have more than 1 number.\n"));
	else
	{
		creat_array(&a, check, i);
		check_dual(i, a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [list of integers]\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (argc < 3)
		spliting(argv, a, 1);
	if (argc >= 3)
		spliting(argv, a, 2);
	//remplir un b pour test
	ps_lstadd_back(&b, ps_lstnew(90));
	ps_lstadd_back(&b, ps_lstnew(96));
	ps_lstadd_back(&b, ps_lstnew(69));
	ps_lstadd_back(&b, ps_lstnew(42));
	//printf("Piles b : ");
	//print_stack(b);
	// Affiche la pile initiale
	//printf("Pile a : ");
	//print_stack(a);
	// Effectue chaque opération une par une pour tester
	//rrb(&b);
	//printf("Pile après rrb : ");
	//print_stack(b);
	//printf("Piles b : ");
	//print_stack(b);
	ps_lstclear(&a);
	ps_lstclear(&b);
	return (0);
}
