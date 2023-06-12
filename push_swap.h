/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:54:45 by nsion             #+#    #+#             */
/*   Updated: 2023/06/12 21:16:06 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf/libftprintf.h"

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
}			t_stack;

typedef struct s_data
{
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}		t_data;

//instruction
void	sa(t_stack **a);

void	sb(t_stack **b);

void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);

void	pb(t_stack **a, t_stack **b);

void	ra(t_stack **a);

void	rb(t_stack **b);

void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);

void	rrb(t_stack **b);

void	rrr(t_stack **a, t_stack **b);

// mini_lib.c
void	ps_lstadd_back(t_stack **lst, t_stack *new);

void	ps_lstadd_front(t_stack **lst, t_stack *new);

t_stack	*ps_lstnew(int content);

int		ps_atoi(const char *nptr);

void	ps_lstclear(t_stack **lst);

t_stack	*ps_lstlast(t_stack *lst);

int		ft_strlen(const char *str);

char	*ft_strdup(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_split(char const *s, char c);

int		ft_isdigit(char c);

int		ft_lstsize(t_stack *src);

//algo_utils
void	bubble_sort(int *arr, int arr_len);

int		find_big_num(t_stack *lst);

int		find_small_num(t_stack *lst_a);

int		find_after_smallnum(t_stack *lst_a);

int		find_big_num_index(t_stack *lst, int max);

//algo
void	from_a_to_b(t_stack **a, t_stack **b, int *array, t_data *data);

void	from_b_to_a(t_stack **a, t_stack **b, int *array, t_data *data);

void	check_cases(t_stack **a, t_stack **b, int *array, t_data *data);

void	check_case2(t_stack **a, t_data *data);

void	not_max_num(t_stack **a, t_stack **b, t_data *data);

//starting
void	three(t_stack **a);

void	five(t_stack **a, t_stack **b);

int		is_sorted(t_stack *a);

void	sort(t_stack **a, t_stack **b, int *array, t_data *data);

#endif