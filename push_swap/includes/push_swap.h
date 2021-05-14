/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:59:28 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/14 13:12:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"

# define ARGS_NUMBER 0
# define ARGS_TYPE_ERROR 1
# define MALLOC_ERROR 2

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

/*
** UTILS
*/

void	ft_stackadd_back(t_stack **alst, t_stack *new);
t_stack	*ft_stacknew(int content);
void	ft_stackclear(t_stack **lst);
void	print_stack(t_stack *a, t_stack *b);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
t_list	*ft_lstnew(char *content);

/*
** LIBFT_UTILS
*/

int		ft_atoi(const char *str);
void	print_errors(int error);
char	*ft_strdup(const char *str);
int		ft_strncmp(const char *s1, const char *s2);
void	ft_putstr(char *str);

/*
**	SWAP
*/

void	swap(t_stack **stack);
void	swap_swap(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	rotate_rotate(t_stack **a, t_stack **b);
void	r_reverse(t_stack **stack);
void	r_r_reverse(t_stack **a, t_stack **b);

#endif