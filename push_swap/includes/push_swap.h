/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:59:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/07 16:23:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../get_next_line/get_next_line.h"

# define ARGS_NUMBER 0
# define ARGS_TYPE_ERROR 1
# define MALLOC_ERROR 2
# define DUPLICATES_ARGS 3
# define INVALID_MOVE 4

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/*
** STACK UTILS
*/

void	ft_stackadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_stacknew(int content);
void	ft_stackclear(t_stack **lst);
int		ft_stacksize(t_stack *stack, int *size);

/*
** LST UTILS
*/

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(char *content);

/*
** BOTH UTILS
*/

void	fill_struct(int argc, char **argv, t_stack **stack);

/*
** LIBFT_UTILS
*/

int		ft_atoi(const char *str, t_stack **stack);
void	print_errors(int error);
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_putstr(const char *str);
void	exit_message(int error, t_stack **stack);

/*
**	SWAP
*/

void	swap(t_stack **stack, const char *to_print);
void	swap_swap(t_stack **a, t_stack **b, const char *to_print);
void	push_a(t_stack **a, t_stack **b, const char *to_print);
void	push_b(t_stack **a, t_stack **b, const char *to_print);
void	rotate(t_stack **stack, const char *to_print);
void	rotate_rotate(t_stack **a, t_stack **b, const char *to_print);
void	r_reverse(t_stack **stack, const char *to_print);
void	r_r_reverse(t_stack **a, t_stack **b, const char *to_print);

/*
** ERROR
*/

int		check_args(int argc, char **argv);

/*
**	PUSH_SWAP
*/

int		get_median_value(t_stack *stack, int len, t_stack *free_on_error);
void	swap_med_simple(t_stack **a, t_stack **b, int *groups, int current);
int		*get_swap_groups(t_stack *a);
void	re_swap(t_stack **a, t_stack **b, int **groups, int *current);
int		get_up_median_value(t_stack *stack, int len, int med, int size);
void	tiny_swap(t_stack **a);
void	swap_med_simple_three(t_stack **a, t_stack **b,
			int *groups, int current);

/*
** CHECKER
*/

void	exit_entry(t_list **entry, t_stack **a, char *line);
int		get_p(t_stack *stack, int value);

#endif