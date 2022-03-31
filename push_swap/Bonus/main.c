/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:38:26 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 18:45:53 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write (1, "Error\n", 6);
	return (0);
}

int	free_all(char **argv, t_data *data, int init_argv)
{
	int		i;
	t_list	*tmp;

	if (data->size > 0 && init_argv == 100500)
	{
		i = -1;
		while (++i <= data->size)
			free(argv[i]);
		free (argv);
	}
	while (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		free(tmp);
	}
	while (data->stack_b)
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		free(tmp);
	}
	if (data->res)
		free(data->res);
	return (1);
}

void	init_data(t_data *data)
{
	data->arg = 0;
	data->size = 0;
	data->error = 0;
	data->arr = NULL;
	data->res = ft_strdup("\0");
	if (!data->res)
		data->error = 10;
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*tmp;
	int		i;
	int		init_argv;

	init_data(&data);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ', &argc, &data.size);
		init_argv = 100500;
	}
	i = 1;
	while (i < argc)
	{
		tmp = ft_lstnew(ft_atoi(argv[i], &data));
		ft_lstadd_back(&data.stack_a, tmp);
		i++;
	}
	start_sort(&data);
	if (data.error != 0)
		return (error() + free_all(argv, &data, init_argv));
	if (argc >= 3)
		start_checker(&data, 1);
	free_all(argv, &data, init_argv);
	return (0);
}
