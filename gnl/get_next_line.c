/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 11:20:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 17:05:08 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buffer;
	ssize_t		cp_len;

	if (!line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0 ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	cp_len = 1;
	while ((!save || !is_in_str(save, '\n')) &&
			(cp_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[cp_len] = 0;
		if (!(save = ft_strjoin(save, buffer)))
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	if (cp_len < 0 || !(*line = ft_strdup_until(save, '\n')))
		return (-1);
	if (!(save = ft_strdup_from(save, ft_strlen_until(save, '\n') + 1)))
		return (-1);
	return (cp_len == 0 ? 0 : 1);
}
