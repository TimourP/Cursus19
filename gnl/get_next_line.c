/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:49:11 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/23 11:12:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	str[MAX_FD][BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		cp_len;

	if (!line)
		return (-1);
	*line = NULL;
	if (str[fd][0])
	{
		*line = ft_strdup_until(str[fd], '\n');
		ft_strcpy_from(str[fd], str[fd], '\n');
	}
	if (str[fd][0])
		return (1);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[cp_len] = 0;
		if (!ft_is_in_str(buffer, '\n'))
			*line = ft_strjoin_until(*line, buffer, 0);
		else
		{
			*line = ft_strjoin_until(*line, buffer, '\n');
			ft_strcpy_from(str[fd], buffer, '\n');
			return (1);
		}
	}
	return (0);
}