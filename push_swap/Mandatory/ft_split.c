/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 09:02:12 by hzona             #+#    #+#             */
/*   Updated: 2021/10/09 16:28:25 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	word_len(const char *str, char c)
{
	size_t			i;
	size_t			count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i + 1] && str[i + 1] == c)
			|| (str[i] != c && !str[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static size_t	len_split(const char *str, char c)
{
	size_t			i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**clean_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ((void *)0);
}

void	move_start(char const *s, char c, size_t *start)
{
	while (s[*start] == c)
		*start = *start + 1;
}

char	**ft_split(char const *s, char c, int *argc, int *sizedata)
{
	size_t			i;
	size_t			start;
	char			**arr;

	i = 0;
	start = 0;
	if (!s)
		return ((void *)0);
	*argc = word_len(s, c) + 1;
	*sizedata = (*argc - 1);
	arr = (char **)malloc(sizeof(char *) * (1 + (*argc)));
	if (!arr)
		return ((void *)0);
	arr[0] = ft_strdup("push_swap\0");
	while (++i < (size_t)(*argc))
	{
		move_start (s, c, &start);
		arr[i] = ft_substr(s, start, len_split(&s[start], c));
		if (!arr[i])
			return (clean_split(arr));
		start += len_split(&s[start], c);
	}
	arr[i] = (void *)0;
	return (arr);
}
