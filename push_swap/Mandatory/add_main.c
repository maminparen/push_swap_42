/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:42:04 by hzona             #+#    #+#             */
/*   Updated: 2021/11/03 13:16:05 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int	check_command_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	start_revervse(t_data *data, int reverse)
{
	int	i;

	i = 0;
	while (reverse != i)
	{
		if (reverse > 0)
		{
			command_rotate(data, 'a');
			i ++;
		}
		else
		{
			command_rrotate(data, 'a');
			i --;
		}
	}
}

void	change_reverse(int *reverse, int argc, t_data *data)
{
	if (argc == 6 && check_command_count(data->res) > 12)
	{
		if (*reverse >= 0 && *reverse < 3)
			*reverse = *reverse + 1;
		else if (*reverse == 3)
			*reverse = -1;
		else if (*reverse == -1)
			*reverse = -2;
		else
			*reverse = 0;
	}
	else if (argc == 501 && check_command_count(data->res) > 5500)
	{
		if (*reverse >= 0 && *reverse < 250)
			*reverse = *reverse + 1;
		else if (*reverse == 250)
			*reverse = -1;
		else if (*reverse <= -1 && *reverse >= -250)
			*reverse = *reverse - 1;
		else
			*reverse = 0;
	}
	else
		*reverse = 0;
}

void	new_init_sort(t_data *data, int reverse, int argc, char **argv)
{
	int		i;
	t_list	*tmp;

	i = 1;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i], data));
		ft_lstadd_back(&data->stack_a, tmp);
		i++;
	}
	start_revervse(data, reverse);
	start_sort(data);
	change_reverse (&reverse, argc, data);
	if (reverse != 0)
	{
		free_all(argv, data, 0);
		init_data(data);
		new_init_sort(data, reverse, argc, argv);
	}
}
