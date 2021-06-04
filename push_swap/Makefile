# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 11:29:13 by tpetit            #+#    #+#              #
#    Updated: 2021/06/04 11:53:19 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

BOTH_SRCS =	libft_utils.c \
			libft_utils2.c \
			lst_utils.c \
			stack_utils.c \
			swap_functions.c \
			swap_functions2.c \
			both_utils.c \
			main_error.c \

PUSH_SWAP_SRCS = 	push_swap.c \
					push_swap_utils.c \
					push_swap_utils2.c \

CHECKER_SRCS = checker.c \

GNL_SRCS =	get_next_line.c \
			get_next_line_utils.c \

ALL_SWAP_SRCS = $(addprefix push_swap_srcs/, ${PUSH_SWAP_SRCS}) \
				$(addprefix both/, ${BOTH_SRCS}) \
				$(addprefix get_next_line/, ${GNL_SRCS}) \

ALL_CHECK_SRCS =	$(addprefix get_next_line/, ${GNL_SRCS}) \
					$(addprefix checker_srcs/, ${CHECKER_SRCS}) \
					$(addprefix both/, ${BOTH_SRCS}) \

SWAP_OBJS	=	${ALL_SWAP_SRCS:.c=.o}
CHECK_OBJS	=	${ALL_CHECK_SRCS:.c=.o}

NAME	=	push_swap
CHECK_NAME = checker
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

$(NAME):
	@$(CC) $(CFLAGS) $(ALL_SWAP_SRCS) -o $(NAME)
	@echo "${GREEN}Push_swap executable ready!${RESET}"

all:			$(NAME) $(CHECK_NAME)

$(CHECK_NAME):
	@$(CC) $(CFLAGS) $(ALL_CHECK_SRCS) -o $(CHECK_NAME)
	@echo "${GREEN}Checker executable ready!${RESET}"

clean:			
	@rm -f $(SWAP_OBJS)
	@rm -f $(SWAP_OBJS)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECK_NAME)

allup : all clean

re:		fclean all

re_checker: fclean checker

.PHONY:	all clean fclean allup re re_checker