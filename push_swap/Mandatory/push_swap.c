/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:23:04 by hzona             #+#    #+#             */
/*   Updated: 2021/11/03 12:56:59 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*result_str(char sym)
{
	if (sym == '0')
		return ("sa\n");
	else if (sym == '1')
		return ("sb\n");
	else if (sym == '2')
		return ("ss\n");
	else if (sym == '3')
		return ("pa\n");
	else if (sym == '4')
		return ("pb\n");
	else if (sym == '5')
		return ("ra\n");
	else if (sym == '6')
		return ("rb\n");
	else if (sym == '7')
		return ("rr\n");
	else if (sym == '8')
		return ("rra\n");
	else if (sym == '9')
		return ("rrb\n");
	else if (sym == 'r')
		return ("rrr\n");
	return (NULL);
}

int	its_sort(t_list *stack_a)
{
	t_list	*begin;

	begin = stack_a;
	while (begin)
	{
		if (begin->next && begin->content > begin->next->content)
			return (0);
		begin = begin->next;
	}
	return (1);
}

void	start_sort(t_data *data)
{
	char	*com;
	int		i;
	t_list	*tmp;

	tmp = NULL;
	i = 0;
	if (its_sort(data->stack_a))
		return ;
	init_int_arr(data);
	sort_arr(data);
	if (data->error != 0)
		return ;
	data->marker = 0;
	if (data->size < 6)
		small_sort(data, 'a');
	stack_distribute(data, tmp, 0);
	com = ft_strdup("\0");
	while (data->res && data->res[i])
	{
		com = ft_strjoin(com, result_str(data->res[i]));
		i++;
	}
	if (data->res)
		free (data->res);
	data->res = com;
}
