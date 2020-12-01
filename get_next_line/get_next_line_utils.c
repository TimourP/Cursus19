/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:07:42 by tpetit            #+#    #+#             */
/*   Updated: 2020/12/01 17:45:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	*ft_memccat(void *dst, const void *src, int c)
{
	unsigned char	*new_dst;
	unsigned char	*new_src;
	int			i;
	int			j;

	c = (unsigned char)c;
	new_src = (unsigned char*)src;
	new_dst = (unsigned char*)dst;
	i = (int)ft_strlen((const char*)new_dst) - 1;
	j = -1;
	while (new_src[++j] && ++i > -1)
	{
		if (new_src[j] == c)
		{
			new_dst[i] = 0;
			return (&new_src[j + 1]);
		}
		new_dst[i] = new_src[j];
	}
	new_dst[i + 1] = 0;
	return (0);
}

int ft_is_in_str(char *str, char c)
{
    int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t			srcsize;
	unsigned int	i;

	if (size == 0)
		return (ft_strlen((const char *)src));
	if (!src)
		return (0);
	srcsize = ft_strlen(src);
	if (srcsize + 1 < size)
	{
		i = -1;
		while (++i < srcsize + 1)
			dest[i] = src[i];
	}
	else if (size)
	{
		i = -1;
		while (++i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}
	return (srcsize);
}

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	tot;

	if (ft_strlen(dest) < size)
		tot = ft_strlen(src) + ft_strlen(dest);
	else
		tot = size + ft_strlen(src);
	while (*(dest++) && size)
		size--;
	dest--;
	i = -1;
	while (src[++i] && i < size - 1 && size)
		dest[i] = src[i];
	if (size)
		dest[i] = 0;
	return (tot);
}

int		get_next_line(int fd, char **line)
{
	static char	str[MAX_FD][BUFFER_SIZE + 1] = {0};
	char		buffer[BUFFER_SIZE + 1] = {0};
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
		return 1;
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[cp_len] = 0;
		if (!ft_is_in_str(buffer, '\n'))
		{
			ft_strlcat(*line, buffer, 10000);
		}
		else
		{
			ft_strlcpy(str[fd], ft_memccat(*line, buffer, '\n'), BUFFER_SIZE);
			break;
		}
	}
	return (0);
}

int main()
{
	int i;
	char *li = malloc(10000);

	i = open("./test.txt", O_RDONLY);

	for (int u = 0; u < 50 ; u++)
	{
		get_next_line(i, (char**)&li);
		printf("%d : %s\n", u, li);
	}
	close(i);
	return 0;
}