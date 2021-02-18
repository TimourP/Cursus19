/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:45:08 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/18 12:58:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>

# define MAX_FD OPEN_MAX

int		get_next_line(int fd, char **line);
size_t	ft_strlen_until(const char *str, char c);
char	*ft_strdup_until(char *src, char c);
int		ft_is_in_str(char *str, char c);
char	*ft_strjoin_until(char *s1, char *s2, char c);
char	*ft_strdup_from(char *src, char c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32

#endif
