/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:20:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 11:06:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_next_line_end(char **line, char **save, int cp_len)
{
	if (cp_len < 0)
		return (-1);
	*line = ft_strdup_until(*save, '\n');
	if (!*line)
		return (-1);
	*save = ft_strdup_from(*save, ft_strlen_until(*save, '\n') + 1);
	if (!*save && cp_len != 0)
		return (-1);
	if (cp_len == 0)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	ssize_t		cp_len;

	if (!line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	cp_len = 1;
	while (!is_in_str(save, '\n') && cp_len > 0)
	{
		cp_len = read(fd, buffer, BUFFER_SIZE);
		buffer[cp_len] = 0;
		save = ft_strjoin(save, buffer);
		if (!save)
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	return (get_next_line_end(line, &save, cp_len));
}
