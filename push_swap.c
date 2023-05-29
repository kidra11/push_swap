/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/05/29 18:21:04 by nsion            ###   ########.fr       */
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
	printf("Piles b : ");
	print_stack(b);
    // Affiche la pile initiale
	printf("Pile a : ");
	print_stack(a);

    // Effectue chaque opération une par une pour tester
    ra(&a);
    printf("Pile après ra : ");
    print_stack(a);

	printf("Piles b : ");
	print_stack(b);

    /*ra(&a, size);
    printf("Pile après ra : ");
    print_stack(a, size);

    rb(&b, size);
    printf("Pile b après rb : ");
    print_stack(b, 1);

    rr(&a, b, size);
    printf("Pile a après rr : ");
    print_stack(a, size);
    printf("Pile b après rr : ");
    print_stack(b, 1);

    rra(&a, size);
    printf("Pile après rra : ");
    print_stack(a, size);

    rrb(&b, size);
    printf("Pile b après rrb : ");
    print_stack(b, 1);

    rrr(&a, &b, size);
    printf("Pile a après rrr : ");
    print_stack(a, size);
    printf("Pile b après rrr : ");
    print_stack(b, 1);*/

	ps_lstclear(&a);
	ps_lstclear(&b);
    return 0;
}