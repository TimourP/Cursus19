/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 15:01:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
