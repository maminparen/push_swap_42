/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:39:38 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 11:39:38 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_piece(t_data *data, char stack, int extr)
{
	int		i;
	int		first;
	int		last;
	t_list	*buf;

	if (stack == 'a')
		data->buf = data->stack_a;
	if (stack == 'b')
		data->buf = data->stack_b;
	i = 0;
	first = 0;
	buf = data->buf;
	while (buf)
	{
		if (buf->index <= extr && buf->index >= extr)
			last = i;
		if (!first && buf->index <= extr && buf->index >= extr)
			first = i;
		buf = buf->next;
		i++;
	}
	if (first <= lsts(data->buf) - last)
		return (1);
	return (-1);
}

int	check_sort_norm(t_data *data)
{
	if (lsts(data->buf) != 3 || (its_sort(data->stack_a)
			&& lsts(data->stack_a) == data->size))
		return (1);
	return (0);
}

void	find_max_step_norm(int i, int *p_res, int *p_new_step, int new)
{
	if (i > *p_res)
	{
		*p_res = i;
		*p_new_step = new;
	}
}

void	find_score_a(t_data *data)
{
	int		len;
	int		i;
	t_list	*tmp;

	len = lsts(data->stack_a);
	tmp = data->stack_a;
	i = 0;
	while (tmp)
	{
		tmp->score = i;
		tmp = tmp->next;
		if (len % 2 == 1 && i == len / 2)
			break ;
		i++;
		if (len % 2 == 0 && i == (len + 1) / 2)
			break ;
	}
	while (tmp)
	{
		tmp->score = i;
		tmp = tmp->next;
		i--;
	}
}

void	find_score_b(t_data *data)
{
	int		len;
	int		i;
	t_list	*tmp;

	len = lsts(data->stack_b);
	tmp = data->stack_b;
	i = 1;
	while (tmp)
	{
		tmp->score = i;
		tmp = tmp->next;
		if (len % 2 == 1 && i == (len + 2) / 2)
			break ;
		i++;
		if (len % 2 == 0 && i == (len / 2) + 1)
			break ;
	}
	while (tmp)
	{
		tmp->score = i;
		tmp = tmp->next;
		i--;
	}
}
