/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:33:33 by nsion             #+#    #+#             */
/*   Updated: 2023/05/29 18:14:58 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_stack	*ps_lstnew(int content)
{
	t_stack	*nv;

	nv = malloc(sizeof(t_stack));
	if (!nv)
		return (0);
	nv->nb = content;
	nv->next = 0;
	return (nv);
}

int	ps_atoi(const char *nptr)
{
	size_t	i;
	size_t	k;
	size_t	nb;

	i = 0;
	nb = 0;
	k = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			k *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return (nb * k);
}

void	ps_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst));
		(*lst) = tmp;
	}
}

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

