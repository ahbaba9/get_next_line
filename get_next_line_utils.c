/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:04:20 by amine             #+#    #+#             */
/*   Updated: 2022/12/08 00:38:34 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char) c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*a;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	a = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		a[i] = s2[j];
		j++;
		i++;
	}
	a[i] = '\0';
	free (s1);
	return (a);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	p = malloc(ft_strlen(s1) * sizeof(char) + 1);
	i = 0;
	if (p == 0)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
