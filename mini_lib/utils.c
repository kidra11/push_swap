/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsion <nsion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:55:26 by nsion             #+#    #+#             */
/*   Updated: 2023/06/11 13:56:02 by nsion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
