# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 19:55:10 by tpetit            #+#    #+#              #
#    Updated: 2021/06/02 13:57:48 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

SRCS =	ft_strlen.c \
		ft_atoi.c \
		ft_putnbr.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAG = -Wall -Wextra -Werror
NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $(OBJS)
	@echo "${GREEN}libft.a created${RESET}"

.c.o:
	@gcc $(CFLAG) -c -I./ $< -o ${<:.c=.o}

clean:
	@rm -f $(OBJS) $(OBJSB)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re