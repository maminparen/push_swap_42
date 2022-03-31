/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:01:44 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 17:03:11 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str, t_data *data)
{
	int				i;
	int				minus;
	unsigned long	num;

	i = 0;
	num = 0;
	while (ft_isspace(str[i]))
		i++;
	minus = 1;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0');
		if ((num > INT_MAX && minus == 1) || (num - 1 > INT_MAX && minus == -1))
			data->error = 1;
	}
	if (str[i] && !ft_isdigit(str[i]))
		data->error = 3;
	return (minus * (int)num);
}

int	next_flag(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (0);
	tmp = lst;
	while (tmp)
	{
		if (tmp->flag)
			break ;
		tmp = tmp->next;
	}
	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->flag)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}
