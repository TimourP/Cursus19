/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:02:05 by tpetit            #+#    #+#             */
/*   Updated: 2021/06/09 16:10:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	philo_lst_clear(t_philo_lst **lst)
{
	t_philo_lst	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		pthread_mutex_destroy((*lst)->philo->right_fork);
		free((*lst)->philo->right_fork);
		free((*lst)->philo);
		free(*lst);
		*lst = tmp;
	}
}

t_philo_lst	*philo_lst_new(t_philo *content)
{
	t_philo_lst	*new;

	new = malloc(sizeof(t_philo_lst));
	if (!new)
		return (NULL);
	new->philo = content;
	new->next = NULL;
	return (new);
}

void	philo_lst_add_back(t_philo_lst **alst, t_philo_lst *new)
{
	t_philo_lst	*tmp;

	if (!alst || !*alst)
	{
		if (!alst)
			return ;
		*alst = new;
		return ;
	}
	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
