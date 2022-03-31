/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_distribute.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:21:09 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 11:21:09 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_arr(t_list *stack_a, int max_step, int *p_marker, int res)
{
	int		i;
	int		index_first;
	int		new_step;
	t_list	*tmp;

	while (*p_marker < max_step)
	{
		tmp = stack_a->next;
		index_first = stack_a->index;
		i = 0;
		while (tmp)
		{
			if (tmp->index > index_first
				&& tmp->index <= index_first + *p_marker)
			{
				i++;
				index_first = tmp->index;
			}
			tmp = tmp->next;
		}
		find_max_step_norm(i, &res, &new_step, *p_marker);
		*p_marker = *p_marker + 1;
	}
	*p_marker = new_step;
	return (res);
}

int	find_start_step(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		max;
	int		step;
	int		start_ind;

	if (!data->stack_a)
		return (0);
	start_ind = data->stack_a->index;
	max = find_max_arr(data->stack_a, (data->size / 10) + 3, &data->marker, 0);
	tmp = data->stack_a->next;
	i = 0;
	while (tmp)
	{
		step = 0;
		i = find_max_arr(tmp, (data->size / 10) + 3, &step, 0);
		if (i > max)
		{
			start_ind = tmp->index;
			max = i;
			data->marker = step;
		}
		tmp = tmp->next;
	}
	return (start_ind);
}

void	init_sort_flag(t_data *data)
{
	int		start;
	t_list	*tmp;

	start = find_start_step(data);
	tmp = data->stack_a;
	while (tmp)
	{
		if (tmp->index >= start && tmp->index <= start + data->marker)
		{
			tmp->flag = 1;
			start = tmp->index;
		}
		tmp = tmp->next;
	}
}

int	check_flag(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp)
	{
		if (!tmp->flag)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	stack_distribute(t_data *data, t_list *tmp, int index_first)
{
	init_sort_flag(data);
	while (data->stack_a && check_flag(data))
	{
		tmp = data->stack_a;
		if (tmp->next && tmp->flag && !tmp->next->flag && tmp->index
			> tmp->next->index && tmp->next->index > index_first)
		{
			command_swap(data, 'a');
			data->stack_a->flag = 1;
		}
		else if (tmp->next && !tmp->flag && tmp->next->flag && tmp->index
			> tmp->next->index && tmp->index < next_flag(tmp))
		{
			data->stack_a->flag = 1;
			command_swap(data, 'a');
		}
		else if (!tmp->flag)
			command_push(data, 'b');
		else
		{
			index_first = tmp->index;
			command_rotate(data, 'a');
		}
	}
	start_next(data);
}
