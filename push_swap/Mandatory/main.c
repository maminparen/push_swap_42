/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:38:26 by hzona             #+#    #+#             */
/*   Updated: 2021/11/03 13:16:42 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write (1, "Error\n", 6);
	return (0);
}

void	free_arr(t_data *data)
{
	if (data->arr)
		free (data->arr);
	if (data->res)
		free(data->res);
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
	free_arr(data);
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
	int		init_argv;

	init_data(&data);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ', &argc, &data.size);
		init_argv = 100500;
	}
	new_init_sort(&data, 0, argc, argv);
	if (data.error != 0)
		return (error() + free_all(argv, &data, init_argv));
	write (1, data.res, ft_strlen(data.res));
	free_all(argv, &data, init_argv);
	return (0);
}
