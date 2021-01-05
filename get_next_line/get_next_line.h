/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:06:50 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/05 14:14:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <limits.h>

# include <stdio.h>

# define MAX_FD OPEN_MAX

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strdup_until(char *src, char c);
void	ft_strcpy_from(char *dst, char *src, char c);
int		ft_is_in_str(char *str, char c);
char	*ft_strjoin_until(char *s1, char *s2, char c);
char	*ft_strcpy(char *dest, char *src);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32

#endif