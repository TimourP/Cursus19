/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 18:25:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/22 18:27:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	ssize_t		cp_len;

	if (!line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0 ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	cp_len = 1;
	while (!is_in_str(save[fd], '\n') && cp_len > 0)
	{
		cp_len = read(fd, buffer, BUFFER_SIZE);
		buffer[cp_len] = 0;
		if (!(save[fd] = ft_strjoin(save[fd], buffer)))
		{
			free(buffer);
			return (-1);
		}
	}
	free(buffer);
	if (cp_len < 0 || !(*line = ft_strdup_until(save[fd], '\n')))
		return (-1);
	if (!(save[fd] = ft_strdup_from(save[fd], ft_strlen_until(save[fd], '\n') + 1))
		&& cp_len != 0)
		return (-1);
	return (cp_len == 0 ? 0 : 1);
}
