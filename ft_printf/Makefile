# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:36:46 by tpetit            #+#    #+#              #
#    Updated: 2021/01/06 17:09:56 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	convert_c.c \
		convert_d.c \
		convert_p.c \
		convert_s.c \
		convert_u.c \
		convert_x.c \
		convert_xk.c \
		ft_printf_utils.c \
		ft_printf.c \
		libft_utils.c \

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