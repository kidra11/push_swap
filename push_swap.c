/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/06/03 20:27:28 by nsion            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**check;

	if (argc < 2)
	{
		printf("Usage: ./push_swap [list of integers]\n");
		return (0);
	}
	a = NULL;
	b = NULL;
	if (argc < 3)
	{
		check = ft_split(argv[1], ' ');
		//compteur de tableau
		//si 1 seul nombre return(printf("Error : you must have more then 1 number.\n"));
		//si plus de 1 nombre creat_array(&a, check, nombre de tableau)
	}
	if (argc >= 3)
		creat_array(&a, argv, argc);
	//remplir un b pour test
	ps_lstadd_back(&b, ps_lstnew(90));
	ps_lstadd_back(&b, ps_lstnew(96));
	ps_lstadd_back(&b, ps_lstnew(69));
	ps_lstadd_back(&b, ps_lstnew(42));
	printf("Piles b : ");
	print_stack(b);
	// Affiche la pile initiale
	printf("Pile a : ");
	print_stack(a);
	// Effectue chaque opération une par une pour tester
	rrb(&b);
	printf("Pile après rrb : ");
	print_stack(b);
	printf("Piles b : ");
	print_stack(b);
	ps_lstclear(&a);
	ps_lstclear(&b);
	return (0);
}
