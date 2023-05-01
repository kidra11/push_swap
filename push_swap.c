/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/05/01 10:52:57 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void creat_list(t_stack **a, char **argv, int argc)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
}

void print_stack(int *stack, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    int *a;
    int *b;
    int size;

    if (argc < 2)
    {
        printf("Usage: ./push_swap [list of integers]\n");
        return (0);
    }

    size = argc - 1;
    a = malloc(size * sizeof(int));
    b = malloc(size * sizeof(int));
    for (int i = 1; i < argc; i++)
        a[i - 1] = ft_atoi(argv[i]);

    // Affiche la pile initiale
    printf("Pile a : ");
    print_stack(a, size);

    // Effectue chaque opération une par une pour tester
    sa(a);
    printf("Pile après sa : ");
    print_stack(a, size);

    /*pb(a, b, &size);
    printf("Pile a après pb : ");
    print_stack(a, size);
    printf("Pile b après pb : ");
    print_stack(b, 1);

    ra(a, size);
    printf("Pile après ra : ");
    print_stack(a, size);

    rb(b, size);
    printf("Pile b après rb : ");
    print_stack(b, 1);

    rr(a, b, size);
    printf("Pile a après rr : ");
    print_stack(a, size);
    printf("Pile b après rr : ");
    print_stack(b, 1);

    rra(a, size);
    printf("Pile après rra : ");
    print_stack(a, size);

    rrb(b, size);
    printf("Pile b après rrb : ");
    print_stack(b, 1);

    rrr(a, b, size);
    printf("Pile a après rrr : ");
    print_stack(a, size);
    printf("Pile b après rrr : ");
    print_stack(b, 1);*/

	free(a);
	free(b);
    return 0;
}