# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:36:46 by tpetit            #+#    #+#              #
#    Updated: 2021/02/23 11:59:52 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	convert_s.c \
		ft_printf_utils.c \
		ft_printf_utils1.c \
		ft_printf_utils2.c \
		ft_printf_utils3.c \
		ft_printf.c \

OBJSB = $(SRCSB:.c=.o)
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

allup : all clean

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJSB)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re allup