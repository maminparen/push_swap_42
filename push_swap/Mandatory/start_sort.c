/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:20:58 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 11:20:58 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_best_a(t_data *data, int index_b, int min, int max)
{
	t_list	*tmp;

	max = find_index_extra(data->stack_a, 1);
	min = find_index_extra(data->stack_a, -1);
	if (index_b > max || index_b < min)
		return (min);
	tmp = data->stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->index < index_b && tmp->next->index > index_b)
		{
			tmp = tmp->next;
			break ;
		}
		if (!tmp->next->next)
		{
			if (tmp->next->index < index_b && data->stack_a->index > index_b)
			{
				tmp = data->stack_a;
				break ;
			}
		}
		tmp = tmp->next;
	}
	return (tmp->index);
}

void	find_new_score(t_data *data)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	int		index;

	find_score_b(data);
	find_score_a(data);
	tmp_b = data->stack_b;
	while (tmp_b)
	{
		index = find_best_a(data, tmp_b->index, 0, 0);
		tmp_a = data->stack_a;
		while (tmp_a)
		{
			if (tmp_a->index == index)
				break ;
			tmp_a = tmp_a->next;
		}
		tmp_b->score = tmp_b->score + tmp_a->score;
		tmp_b = tmp_b->next;
	}
}

int	find_bes_score(t_data *data)
{
	int		new_score;
	int		index;
	t_list	*tmp;

	find_new_score(data);
	tmp = data->stack_b;
	index = tmp->index;
	new_score = tmp->score;
	while (tmp)
	{
		if (new_score > tmp->score)
		{
			new_score = tmp->score;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (index);
}

void	push_stack_a(t_data *data, int index_a, int index_b, int check_a)
{
	int	check_b;

	index_b = find_bes_score(data);
	index_a = find_best_a(data, index_b, 0, 0);
	check_b = check_sort_piece(data, 'b', index_b);
	check_a = check_sort_piece(data, 'a', index_a);
	if (check_a == check_b)
	{
		while (data->stack_a->index != index_a
			&& data->stack_b->index != index_b)
			if (check_a == 1)
				command_rr(data);
		else
			command_rrr(data);
	}
	while (data->stack_b->index != index_b)
		if (check_b == 1)
			command_rotate(data, 'b');
	else
		command_rrotate(data, 'b');
	while (data->stack_a->index != index_a)
		if (check_a == 1)
			command_rotate(data, 'a');
	else
		command_rrotate(data, 'a');
}

void	start_next(t_data *data)
{
	while (lsts(data->stack_b))
	{
		push_stack_a(data, 0, 0, 0);
		command_push(data, 'a');
	}
	while (data->stack_a->index != 0)
	{
		if (check_sort_piece(data, 'a', 0) == 1)
			command_rotate(data, 'a');
		else
			command_rrotate(data, 'a');
	}
}
