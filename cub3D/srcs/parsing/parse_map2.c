/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:56:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/23 13:52:43 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list	*list_from_file(char *map_path)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*map_lst;
	t_list	*new;

	fd = open(map_path, O_RDONLY);
	ret = 1;
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
	return (map_lst);
}
