/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 10:20:12 by nsion             #+#    #+#             */
/*   Updated: 2023/07/31 10:22:15 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen_bn(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdup_bn(char *s)
{
	int		j;
	int		i;
	char	*l;

	if (!s || !ft_strlen(s))
		return (NULL);
	i = 0;
	j = ft_strlen(s);
	l = (char *)malloc((j + 1) * sizeof(char));
	if (l == 0)
		return (0);
	while (i < j)
	{
		l[i] = s[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		l;
	int		i;
	int		k;

	if (!s1)
		return (ft_strdup(s2));
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	l = 0;
	i = 0;
	k = 0;
	while (s1[i])
		str[l++] = s1[i++];
	while (s2[k])
		str[l++] = s2[k++];
	str[l] = '\0';
	free(s1);
	return (str);
}
