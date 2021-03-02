/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 10:56:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/03/02 10:57:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_list		*list_from_file(char *map_path)
{
	int		fd;
	int		ret;
	char	*line;
	t_list	*map_lst;
	t_list	*new;

	fd = open(map_path, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!(new = ft_lstnew(line)))
			return (NULL);
		ft_lstadd_back(&map_lst, new);
	}
	if (ret == -1 || !(new = ft_lstnew(line)))
		return (NULL);
	ft_lstadd_back(&map_lst, new);
	return (map_lst);
}
