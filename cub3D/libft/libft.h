/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:54:04 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/25 12:14:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_lstadd_back(t_list **alst, t_list *new);
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstprint(t_list *lst);
int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_itoa_base(int n, int base_len, const char *base);
char			**ft_split(char const *str, char c);
size_t			number_len(int n, int base_len);

#endif
