/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:06:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/24 16:47:35 by tpetit           ###   ########.fr       */
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

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return ((char *)&str[i]);
	if (str[i] == 0 && c == 0)
		return ((char *)&str[i]);
	return (NULL);
}

int		ft_strchrn(const char *str, int c)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return(i);
	if (str[i] == 0 && c == 0)
		return (i);
	return (ft_strlen(str) - 1);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int i;
	unsigned int dstsize;

	i = -1;
	dstsize = 0;
	while (dest[++i])
		dstsize++;
	i = -1;
	while (src[++i] && nb--)
		dest[dstsize + i] = src[i];
	dest[dstsize + i] = '\0';
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int srcsize;
	unsigned int i;

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

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*point;

	i = -1;
	point = 0;
	while (str[++i])
		if (str[i] == c)
			point = (char *)&str[i];
	if (str[i] == 0 && c == 0)
		return ((char *)&str[i]);
	return (point);
}

int		get_next_line(int fd, char **line)
{
	static char	str[MAX_FD][BUFFER_SIZE + 1] = {0};
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		cp_len;

	*line[0] = 0;
	if (str[fd][0])
	{
		ft_strncat(*line, str[fd], ft_strchrn(str[fd], '\n'));
		ft_strlcpy(str[fd], ft_strchr(str[fd], '\n') ? ft_strchr(str[fd], '\n') + 1 : "", BUFFER_SIZE);
	}
	if (str[fd][0] != 0)
		return (0);
	while ((cp_len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[cp_len] = 0;
		if (!ft_strchr(buffer, '\n'))
			ft_strncat(*line, buffer, cp_len);
		else
		{
			printf("%s\n", buffer);
			ft_strncat(str[fd], ft_strchr(buffer, '\n') + 1, BUFFER_SIZE);
			ft_strncat(*line, buffer, ft_strchrn(buffer, '\n'));
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
		printf("%d : str : %s\n", u, li);
	}
	close(i);
	return 0;
}