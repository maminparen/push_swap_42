/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrforcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:27:33 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 22:12:06 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_idnex_stack(t_data *data)
{
	t_list	*tmp;
	int		i;

	tmp = data->stack_a;
	while (tmp)
	{
		i = 0;
		while (i < data->size)
		{
			if (data->arr[i] == tmp->content)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	sort_arr(t_data *data)
{
	int	i;
	int	tmp;

	if (data->error != 0)
		return ;
	i = 0;
	while (i < data->size)
	{
		if (i + 1 < data->size && data->arr[i] > data->arr[i + 1])
		{
			tmp = data->arr[i];
			data->arr[i] = data->arr[i + 1];
			data->arr[i + 1] = tmp;
			i = 0;
		}
		else if (i + 1 < data->size && data->arr[i] == data->arr[i + 1])
		{
			data->error = 3;
			i++;
		}
		else
			i++;
	}
	add_idnex_stack(data);
}

void	init_int_arr(t_data *data)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = lsts(data->stack_a);
	data->arr = malloc(sizeof(int) * len);
	if (!data->arr)
	{
		data->error = 2;
		return ;
	}
	i = 0;
	tmp = data->stack_a;
	while (i < len)
	{
		data->arr[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	data->size = len;
}
