# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 13:36:46 by tpetit            #+#    #+#              #
#    Updated: 2021/05/19 22:38:16 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CONVERT_SRCS = 	convert_s.c \
				convert_c.c \
				convert_di.c \
				convert_p.c \
				convert_u.c \
				convert_x.c \
				convert_upper_x.c \
				convert_percent.c \

UTILS_SRCS =	ft_printf_utils.c \
				ft_printf_utils1.c \
				ft_printf_utils2.c \
				ft_printf_utils3.c \
				ft_printf_utils4.c \

SRCS = 	ft_printf.c \
		$(addprefix srcs/convert/, ${CONVERT_SRCS}) \
		$(addprefix srcs/utils/, ${UTILS_SRCS}) \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

allup : all clean

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re allup