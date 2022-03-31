/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:34:42 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 18:09:48 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	res = (char *) malloc(len + 1);
	if (res == (void *)0)
		return ((void *)0);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s)
		return ((void *)0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == (void *)0)
		return ((void *)0);
	while (i < len)
	{
		if (s[start + i] != '\0' && start < ft_strlen(s))
			res[i] = s[start + i];
		else
			res[i] = '\0';
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*res;
	int		i;
	int		k;

	if (!s1 && !s2)
		return ((void *)0);
	i = 0;
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == (void *)0 || !s1 || !s2)
		return ((void *)0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	k = 0;
	while (s2[k])
	{
		res[i + k] = s2[k];
		k++;
	}
	res[i + k] = '\0';
	if (s1)
		free (s1);
	return (res);
}
