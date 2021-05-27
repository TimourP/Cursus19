/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:54:04 by tpetit            #+#    #+#             */
/*   Updated: 2021/05/27 15:05:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_atoi_base(char *str, char *base);

#endif
