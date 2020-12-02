/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:06:50 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/02 11:08:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define MAX_FD 1024

int		get_next_line(int fd, char **line);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
int		ft_is_in_str(char *str, char c);
void	*ft_memccat(void *dst, const void *src, int c);
size_t	ft_strlen(const char *str);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32

#endif