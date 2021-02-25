# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 19:55:10 by tpetit            #+#    #+#              #
#    Updated: 2021/02/25 12:08:21 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_lstadd_back.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstprint.c \
		ft_strncmp.c \
		ft_strlen.c \
		ft_atoi.c \
		ft_strtrim.c \
		ft_itoa_base.c \
		ft_split.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS) $(OBJSB)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re