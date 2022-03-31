/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 17:25:56 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 22:35:50 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_command_two(t_data *data, char *s)
{
	if (s[0] == 'r' && s[1] == 'r' && s[2] == 'r'
		&& s[3] == '\n' && ft_strlen(s) == 4)
		command_rrr(data);
	else if (s[0] != '\0')
		data->error = 4;
}

void	go_command(t_data *data, char *s)
{
	if (s[0] == 's' && s[1] == 'a' && s[2] == '\n' && ft_strlen(s) == 3)
		command_swap(data, 'a');
	else if (s[0] == 's' && s[1] == 'b' && s[2] == '\n' && ft_strlen(s) == 3)
		command_swap(data, 'b');
	else if (s[0] == 's' && s[1] == 's' && s[2] == '\n' && ft_strlen(s) == 3)
		command_ss(data);
	else if (s[0] == 'p' && s[1] == 'a' && s[2] == '\n' && ft_strlen(s) == 3)
		command_push(data, 'a');
	else if (s[0] == 'p' && s[1] == 'b' && s[2] == '\n' && ft_strlen(s) == 3)
		command_push(data, 'b');
	else if (s[0] == 'r' && s[1] == 'a' && s[2] == '\n' && ft_strlen(s) == 3)
		command_rotate(data, 'a');
	else if (s[0] == 'r' && s[1] == 'b' && s[2] == '\n' && ft_strlen(s) == 3)
		command_rotate(data, 'b');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == '\n' && ft_strlen(s) == 3)
		command_rr(data);
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'a'
		&& s[3] == '\n' && ft_strlen(s) == 4)
		command_rrotate(data, 'a');
	else if (s[0] == 'r' && s[1] == 'r' && s[2] == 'b'
		&& s[3] == '\n' && ft_strlen(s) == 4)
		command_rrotate(data, 'b');
	else
		go_command_two(data, s);
}

char	*get_next_line(int fd, char *line, int *read_b)
{
	char	buffer[2];
	ssize_t	rb;

	rb = 1;
	while (rb)
	{
		rb = read(fd, buffer, 1);
		*read_b = rb;
		if (rb < 0)
			return (line);
		buffer[1] = '\0';
		line = ft_strjoin(line, buffer);
		if (buffer[0] == '\n')
			return (line);
	}
	*read_b = rb;
	return (line);
}

void	start_checker(t_data *data, int read_b)
{
	char	*line;

	line = NULL;
	data->size = lsts(data->stack_a);
	read_b = 1;
	while (read_b && read_b != -1 && !data->error)
	{
		if (!line)
			line = ft_strdup("\0");
		line = get_next_line(0, line, &read_b);
		go_command(data, line);
		free (line);
		line = NULL;
	}
	if (line)
		free (line);
	if (!data->error)
	{
		if (its_sort(data->stack_a) && lsts(data->stack_a) == data->size)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write (1, "Error\n", 6);
}
