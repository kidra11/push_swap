/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_lib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:33:33 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:15:52 by nsion            ###   ########.fr       */
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
	size_t		i;
	int			k;
	long long	nb;

	i = 0;
	nb = 0;
	k = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i++] == '-')
		{
			if (!ft_isdigit(nptr[i]))
				exit(ft_printf("Error: no digit.\n"));
			k *= -1;
		}
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i])
		nb = nb * 10 + nptr[i++] - 48;
	if (nptr[i])
		exit(ft_printf("Error: non digit character.\n"));
	if ((nb * k) > 2147483647 || (nb * k) < -2147483648)
		exit(ft_printf("Error: out of limits.\n"));
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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	int		i;
	char	*l;

	i = 0;
	l = (char *)malloc(ft_strlen((char *)s) + 1 * sizeof(char));
	if (l == 0)
		return (0);
	while (s[i])
	{
		l[i] = s[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*nv;
	int		i;

	if (!s)
		return (NULL);
	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	else if ((int)len > ft_strlen(s + start))
		nv = (char *)malloc(((ft_strlen(s) + 1) - start) * sizeof(char));
	else
		nv = (char *) malloc((len + 1) * sizeof(char));
	i = 0;
	if (nv == 0)
		return (NULL);
	while (len-- > 0 && s[start])
		nv[i++] = s[start++];
	nv[i] = '\0';
	return (nv);
}

static int	count_word(char const *s, char c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (s[i])
		{
			k++;
			while (c != s[i] && s[i])
				i++;
		}
	}
	return (k);
}

static int	get_next_word(char const *s, int i, char c)
{
	int	t;
	int	p;

	t = i;
	p = 0;
	while (c != s[t] && s[t])
		t++;
	p = t - i;
	if (!p)
		return (t);
	return (p);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		y;

	i = 0;
	y = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc((count_word(s, c) + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	while (s[i])
	{
		while (c == s[i] && s[i])
			i++;
		if (c != s[i] && s[i])
		{
			str[y] = ft_substr(s, i, get_next_word(s, i, c));
			i += get_next_word(s, i, c);
			y++;
		}
	}
	str[y] = 0;
	return (str);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}