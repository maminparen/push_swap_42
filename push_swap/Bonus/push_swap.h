/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzona <hzona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 10:23:29 by hzona             #+#    #+#             */
/*   Updated: 2021/10/29 18:43:30 by hzona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MAX 2147483647
# define START 2

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	unsigned char	flag;
	int				score;

	struct s_list	*next;
}			t_list;

typedef struct s_data
{
	int		arg;
	int		marker;
	int		size;
	int		error;
	int		*arr;
	char	*res;

	t_list	*buf;
	t_list	*stack_a;
	t_list	*stack_b;
}			t_data;

size_t		ft_strlen(const char *string);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *str);
char		*ft_strjoin(char *s1, char const *s2);

char		**ft_split(char const *s, char c, int *argc, int *sizedata);

t_list		*ft_lstnew(int content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			lsts(t_list *lst);

int			ft_atoi(const char *str, t_data *data);
int			next_flag(t_list *lst);

int			its_sort(t_list *stack_a);
void		start_sort(t_data *data);

void		init_int_arr(t_data *data);
void		sort_arr(t_data *data);

int			find_index_extra(t_list *stack, int flag);
void		small_sort(t_data *data, char stack);
void		sort_three(t_data *data, char stack);
void		sort_for(t_data *data, char stack);
void		sort_five(t_data *data, char stack);

void		command_swap(t_data *data, char stack);
void		command_ss(t_data *data);
void		command_push(t_data *data, char stack);
void		command_rotate(t_data *data, char stack);
void		command_rr(t_data *data);

void		command_rrotate(t_data *data, char stack);
void		command_rrr(t_data *data);

int			check_sort_piece(t_data *data, char stack, int extr);
int			check_sort_norm(t_data *data);
void		find_max_step_norm(int i, int *p_res, int *p_new_step, int new);
void		find_score_a(t_data *data);
void		find_score_b(t_data *data);

void		stack_distribute(t_data *data, t_list *tmp, int index_first);

void		start_next(t_data *data);

void		start_checker(t_data *data, int read_b);

#endif