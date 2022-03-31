/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:50:41 by hzona             #+#    #+#             */
/*   Updated: 2021/11/03 13:27:04 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_extra(t_list *stack, int flag)
{
	t_list	*tmp;
	int		res;

	tmp = stack;
	res = stack->index;
	while (tmp)
	{
		if (res < tmp->index && flag > 0)
			res = tmp->index;
		if (res > tmp->index && flag < 0)
			res = tmp->index;
		tmp = tmp->next;
	}
	return (res);
}

void	sort_for(t_data *data, char stack)
{
	int	min;

	if (stack == 'a')
		data->buf = data->stack_a;
	if (stack == 'b')
		data->buf = data->stack_b;
	min = find_index_extra(data->buf, -1);
	if (data->buf->index == min)
	{
		if (stack == 'a')
			command_push(data, 'b');
		else
			command_push(data, 'a');
		sort_three(data, stack);
		command_push(data, stack);
	}
	else
	{
		if (check_sort_piece(data, stack, min) == 1)
			command_rotate(data, stack);
		else
			command_rrotate(data, stack);
		sort_for(data, stack);
	}
}

void	sort_five(t_data *data, char stack)
{
	t_list	*tmp;
	int		min;

	if (stack == 'a')
		tmp = data->stack_a;
	if (stack == 'b')
		tmp = data->stack_b;
	min = find_index_extra(tmp, -1);
	if (tmp->index != min && lsts(tmp) > 4)
	{
		if (check_sort_piece(data, stack, min) == 1)
			command_rotate(data, stack);
		else
			command_rrotate(data, stack);
		sort_five(data, stack);
		return ;
	}
	if (stack == 'a')
		command_push(data, 'b');
	else
		command_push(data, 'a');
	sort_for(data, stack);
	command_push(data, stack);
}

void	sort_three(t_data *data, char stack)
{
	if (stack == 'a')
		data->buf = data->stack_a;
	if (stack == 'b')
		data->buf = data->stack_b;
	if (check_sort_norm(data) == 1)
		return ;
	if (data->buf->index == find_index_extra(data->buf, -1))
	{
		command_swap(data, stack);
		command_rotate(data, stack);
	}
	else if (data->buf->index == find_index_extra(data->buf, 1))
	{
		command_rotate(data, stack);
		if (!(its_sort(data->stack_a) && lsts(data->stack_a) == data->size))
			command_swap(data, stack);
	}
	else if (data->buf->next->index == find_index_extra(data->buf, 1))
	{
		command_rrotate(data, stack);
		if (!(its_sort(data->stack_a) && lsts(data->stack_a) == data->size))
			command_swap(data, stack);
	}
	else
		command_swap(data, stack);
}

void	small_sort(t_data *data, char stack)
{
	t_list	*tmp;
	int		len;

	if (stack == 'a')
		tmp = data->stack_a;
	else
		tmp = data->stack_b;
	if (its_sort(tmp))
		return ;
	len = lsts(tmp);
	if (len == 2)
		command_swap(data, stack);
	if (len == 3)
		sort_three(data, stack);
	if (len == 4)
		sort_for(data, stack);
}
