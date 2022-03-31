/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:10:07 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 17:16:05 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_prelast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next->next != (void *)0)
		lst = lst->next;
	return (lst);
}

void	command_rrotate(t_data *data, char stack)
{
	t_list	*new_first;
	t_list	*new_second;
	t_list	*new_last;

	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (stack == 'a' || stack == 'A')
		new_second = data->stack_a;
	else
		new_second = data->stack_b;
	if (!new_second || !new_second->next)
		return ;
	if (stack == 'a')
		data->res = ft_strjoin(data->res, "8");
	else if (stack == 'b')
		data->res = ft_strjoin(data->res, "9");
	new_first = ft_lstlast(new_second);
	new_last = ft_prelast(new_second);
	new_last->next = NULL;
	ft_lstadd_front(&new_second, new_first);
	if (stack == 'a' || stack == 'A')
		data->stack_a = new_first;
	else
		data->stack_b = new_first;
}

void	command_rrr(t_data *data)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
		return ;
	if (data->stack_a || data->stack_a->next)
	{
		command_rrotate(data, 'A');
		a++;
	}
	if (data->stack_b || data->stack_b->next)
	{
		command_rrotate(data, 'B');
		b++;
	}
	if (a == 1 && b == 1)
		data->res = ft_strjoin(data->res, "r");
	else if (a == 1 && b == 0)
		data->res = ft_strjoin(data->res, "8");
	else if (a == 0 && b == 1)
		data->res = ft_strjoin(data->res, "9");
}
