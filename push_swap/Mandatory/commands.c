/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:10:42 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 17:15:44 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	command_swap(t_data *data, char stack)
{
	t_list	*second;
	t_list	*first;

	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (stack == 'a' || stack == 'A')
		second = data->stack_a;
	else
		second = data->stack_b;
	if (!second || !second->next)
		return ;
	if (stack == 'a')
		data->res = ft_strjoin(data->res, "0");
	else if (stack == 'b')
		data->res = ft_strjoin(data->res, "1");
	first = second->next;
	second->next = second->next->next;
	first->next = second;
	if (stack == 'a' || stack == 'A')
		data->stack_a = first;
	else
		data->stack_b = first;
}

void	command_ss(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (data->stack_a || data->stack_a->next)
	{
		command_swap(data, 'A');
		a++;
	}
	if (data->stack_b || data->stack_b->next)
	{
		command_swap(data, 'B');
		b++;
	}
	if (a == 1 && b == 1)
		data->res = ft_strjoin(data->res, "2");
	else if (a == 1 && b == 0)
		data->res = ft_strjoin(data->res, "0");
	else if (a == 0 && b == 1)
		data->res = ft_strjoin(data->res, "1");
}

void	command_push(t_data *data, char stack)
{
	t_list	*tmp;

	if (stack == 'a')
	{
		if (!data->stack_b)
			return ;
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		tmp->next = NULL;
		ft_lstadd_front(&data->stack_a, tmp);
		data->stack_a = tmp;
		data->res = ft_strjoin(data->res, "3");
	}
	else
	{
		if (!data->stack_a)
			return ;
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		tmp->next = NULL;
		ft_lstadd_front(&data->stack_b, tmp);
		data->stack_b = tmp;
		data->res = ft_strjoin(data->res, "4");
	}
}

void	command_rotate(t_data *data, char stack)
{
	t_list	*new_first;
	t_list	*new_last;

	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (stack == 'a' || stack == 'A')
		new_last = data->stack_a;
	else
		new_last = data->stack_b;
	if (!new_last || !new_last->next)
		return ;
	if (stack == 'a')
		data->res = ft_strjoin(data->res, "5");
	else if (stack == 'b')
		data->res = ft_strjoin(data->res, "6");
	new_first = new_last->next;
	new_last->next = NULL;
	ft_lstadd_back(&new_first, new_last);
	if (stack == 'a' || stack == 'A')
		data->stack_a = new_first;
	else
		data->stack_b = new_first;
}

void	command_rr(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (data->stack_a || data->stack_a->next)
	{
		command_rotate(data, 'A');
		a++;
	}
	if (data->stack_b || data->stack_b->next)
	{
		command_rotate(data, 'B');
		b++;
	}
	if (a == 1 && b == 1)
		data->res = ft_strjoin(data->res, "7");
	else if (a == 1 && b == 0)
		data->res = ft_strjoin(data->res, "5");
	else if (a == 0 && b == 1)
		data->res = ft_strjoin(data->res, "6");
}
