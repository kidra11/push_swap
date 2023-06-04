/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:52:52 by nsion             #+#    #+#             */
/*   Updated: 2023/06/04 11:45:51 by nsion            ###   ########.fr       */
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

int	check_dual(int num, char **tab)
{
	int	i;
	int	j;

	if (!num || !tab)
	{
		ft_printf("Error\n");
		return (0);
	}
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (tab[i] == tab[j])
			{
				ft_printf("Error: Duplicate detected\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	spliting(char **tab)
{
	char	**check;
	int		i;

	check = ft_split(tab[1], ' ');
	while (tab)
		i++;
	//compteur de tableau
	//si 1 seul nombre return(printf("Error : you must have more then 1 number.\n"));
	//si plus de 1 nombre 
	//if(check_dual(compteur tableau, check) == 0)
	//	return (0);
	//creat_array(&a, check, nombre de tableau)

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
		spliting(argv);
	if (argc >= 3)
	{
		if (check_dual(argc, argv) == 0)
			return (0);
		creat_array(&a, argv, argc);
	}
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
