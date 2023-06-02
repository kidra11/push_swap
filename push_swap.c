/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/06/02 19:00:43 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void creat_array(t_stack **a, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ps_lstadd_back(a, ps_lstnew(ps_atoi(argv[i])));
		i++;
	}
}

void print_stack(t_stack *stack)
{
    while(stack)
	{
        printf("%d ", stack->nb);
		stack = stack->next;
	}
	printf("\n");
}

int main(int argc, char **argv)
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
	// a = malloc(sizeof(t_stack));
	// b = malloc(sizeof(t_stack));

	creat_array(&a, argv, argc);

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
    return 0;
}