/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:49:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/20 14:52:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_next_line_end(int cp_len, char **str, char **line)
{
	int ret;

	ret = 0;
	if (cp_len < 0 || !(*line = ft_strdup_until(*str, '\n')))
		return (-1);
	if (ft_strlen_until(*str, 0) >= 1 &&
		(*str)[ft_strlen_until(*str, 0) - 1] == '\n')
		ret = 1;
	if (!(*str = ft_strdup_from(*str, '\n')))
		return (-1);
	if (cp_len == 0 && ft_strlen_until(*str, 0) == 0)
		return (ret);
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
	ssize_t		cp_len;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > MAX_FD ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[cp_len] = 0;
		if (!(str = ft_strjoin_until(str, buffer, 0)))
		{
			free(buffer);
			return (-1);
		}
		if (ft_is_in_str(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (get_next_line_end(cp_len, &str, line));
}
