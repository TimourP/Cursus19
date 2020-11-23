/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:06:17 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/23 15:33:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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

void	get_str_until(char *str, char until, char **dest)
{
	int i;

	i = -1;
	while (str[++i] && str[i] != until)
		printf("je passe\n");
}

int		get_next_line(int fd, char **line)
{
	static char	str[2147483647];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		cp_len;

	str[0] = 0;
	
	while ((!ft_strrchr(str, '\n')) && (cp_len = read(fd, buffer, BUFFER_SIZE)))
	{
		ft_strlcat(str, buffer, 2147483647);
	}
	get_str_until(str, '\n', line);
	return (0);
}

int main()
{
	int i;
	char li[100] = "Hello comment ca va aujourd'hui";

	i = open("./test.txt", O_RDONLY);
	get_next_line(i, (char**)&li);
	get_next_line(i, (char**)&li);
	return 0;
}