/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:56:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/04/19 12:18:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_fd_ret(char *map_path, int *fd, int *ret)
{
	*fd = open(map_path, O_RDONLY);
	*ret = 1;
}

t_list	*list_from_file(char *map_path)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*map_lst;
	t_list	*new;

	set_fd_ret(map_path, &fd, &ret);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret != 1)
			break ;
		new = ft_lstnew(line);
		if (!new)
			return (NULL);
		ft_lstadd_back(&map_lst, new);
	}
	if (ret == -1)
		return (NULL);
	new = ft_lstnew(line);
	if (!new)
		return (NULL);
	ft_lstadd_back(&map_lst, new);
	close(fd);
	return (map_lst);
}
