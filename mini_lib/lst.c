/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:43:53 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:54:30 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

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
