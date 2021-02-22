/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:13:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 17:04:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# define MAX_FD OPEN_MAX

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20

# endif

char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);
int		is_in_str(char *str, char c);
char	*ft_strdup_until(char *src, char c);
char	*ft_strdup_from(char *src, int from);
size_t	ft_strlen_until(char *str, char c);

#endif
