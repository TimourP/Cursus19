/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:24:01 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/13 12:25:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_next_line_end(int fd, int cp_len, char *str[], char **line)
{
	int ret;

	ret = 0;
	if (cp_len < 0 || !(*line = ft_strdup_until(str[fd], '\n')))
		return (-1);
	if (ft_strlen_until(str[fd], 0) >= 1 &&
		str[fd][ft_strlen_until(str[fd], 0) - 1] == '\n')
		ret = 1;
	if (!(str[fd] = ft_strdup_from(str[fd], '\n')))
		return (-1);
	if (cp_len == 0 && ft_strlen_until(str[fd], 0) == 0)
		return (ret);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*str[MAX_FD];
	char		*buffer;
	ssize_t		cp_len;

	if (!str[fd])
		str[fd] = ft_strdup_until("", 0);
	if (!line || fd < 0 || fd > MAX_FD ||
		!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[cp_len] = 0;
		if (!(str[fd] = ft_strjoin_until(str[fd], buffer, 0)))
		{
			free(buffer);
			return (-1);
		}
		if (ft_is_in_str(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (get_next_line_end(fd, cp_len, str, line));
}
