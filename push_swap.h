/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 10:54:45 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 10:57:04 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include "ft_printf/libftprintf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

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

//push_swap.c
void	spliting(char **tab, t_stack **a, int choice);

void	creat_array(t_stack **a, char **argv, int argc);

void	check_dual(t_stack *lst);

void	instructs(char *s, t_stack **a, t_stack **b);

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

//bonus/checkers.c
int		ft_strcmp(const char *s1, const char *s2);

int		is_sorted_bn(t_stack *a, t_stack *b);

void	instructs(char *s, t_stack **a, t_stack **b);

//bonus/instruction.c
void	b_swap(t_stack *stack);

void	b_push(t_stack **src, t_stack **dest);

void	b_rotate(t_stack **stack);

void	b_reverse_rotate(t_stack **stack);

int		b_washing(t_stack **a, t_stack **b, char *s);

//bonus/get_next_line.c
int		find_end(char *s);

char	*copy_line(char *stat);

char	*new_line(char *stat);

char	*reader(int fd, char *stat);

char	*get_next_line(int fd);

//bonus/get_next_line_utils.c
int		ft_strlen_bn(char *s);

char	*ft_strdup_bn(char *s);

char	*ft_strjoin(char *s1, char *s2);

#endif