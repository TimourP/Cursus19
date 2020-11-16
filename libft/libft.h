/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:28:00 by tpetit            #+#    #+#             */
/*   Updated: 2020/11/16 15:13:04 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(char *str);
void    ft_bzero(void *str, size_t len);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isupper(int c);
void	*ft_memcpy(void *dst, void *src, size_t n);
void    *ft_memset(void *str, int c, size_t len);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlcat(char *dest, char *src, unsigned int size);
size_t	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(char *str, char *to_find, size_t len);
char	*ft_strrchr(const char *str, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif