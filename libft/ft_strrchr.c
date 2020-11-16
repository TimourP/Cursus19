/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:43:57 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 10:46:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	int i;
    char *point = 0;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			point = (char *)&str[i];
	}
	if (str[i] == 0 && c == 0){
		return ((char *)&str[i]);
	}
	return (point);
}