/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 09:49:11 by tpetit            #+#    #+#             */
/*   Updated: 2021/01/11 11:47:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int free_and_return(char *to_free, int to_return)
{
	free(to_free);
	return (to_return);
}

int	get_next_line(int fd, char **line)
{
	static char	*str[MAX_FD];
	char		*buffer;
	ssize_t		cp_len;
	int			ret;

	ret = 0;
	if (!str[fd])
		str[fd] = ft_strdup_until("", 0);
	if (fd < 0 || fd > MAX_FD || !(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[cp_len] = 0;
		if (!(str[fd] = ft_strjoin_until(str[fd], buffer, 0)))
			return (free_and_return(buffer, -1));
		if (ft_is_in_str(buffer, '\n'))
			break;
	}
	if (cp_len < 0 || !(*line = ft_strdup_until(str[fd], '\n')))
		return (free_and_return(buffer, -1));
	if (ft_strlen_until(str[fd], 0) >= 1 && str[fd][ft_strlen_until(str[fd], 0) - 1] == '\n')
		ret = 1;
	if (!(str[fd] = ft_strdup_from(str[fd], '\n')))
		return (free_and_return(buffer, -1));
	if (cp_len == 0 && ft_strlen_until(str[fd], 0) == 0)
		return (free_and_return(buffer, ret));
	return (free_and_return(buffer, 1));
}
