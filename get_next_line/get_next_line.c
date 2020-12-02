/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:06:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/02 12:45:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	str[MAX_FD][BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		cp_len;

	*line[0] = 0;
	if (str[fd][0])
	{
		tmp = ft_memccat(*line, str[fd], '\n');
		if (tmp)
			ft_strlcpy(str[fd], tmp, BUFFER_SIZE);
		else
			str[fd][0] = 0;
	}
	if (str[fd][0])
		return (1);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[cp_len] = 0;
		if (!ft_is_in_str(buffer, '\n'))
			ft_strlcat(*line, buffer, 10000);
		else
		{
			if (buffer[0] == '\n')
			{
				str[fd][0] = '\n';
				str[fd][1] = 0;
				ft_strlcat(str[fd], ft_memccat(*line, buffer, '\n'),
							BUFFER_SIZE);
			}
			else
				ft_strlcpy(str[fd], ft_memccat(*line, buffer, '\n'),
							BUFFER_SIZE);
			break ;
		}
	}
	return (cp_len < BUFFER_SIZE ? 0 : 1);
}
