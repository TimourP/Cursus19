/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:45:01 by tpetit            #+#    #+#             */
/*   Updated: 2021/02/16 13:31:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	get_next_line_end(int cp_len, char *str[], char **line)
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
	static char	*str[MAX_FD];
	char		*buffer;
	ssize_t		cp_len;

	if (!line || BUFFER_SIZE <= 0 || read(fd, NULL, 0) != 0 ||
		!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((!str[fd] || !ft_is_in_str(str[fd], '\n')) &&
		(cp_len = read(fd, buffer, BUFFER_SIZE)) > 0)
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
	return (get_next_line_end(cp_len, &(str[fd]), line));
}
