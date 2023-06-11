/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:47:17 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:47:50 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
