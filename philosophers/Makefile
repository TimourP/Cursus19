# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 08:55:26 by tpetit            #+#    #+#              #
#    Updated: 2021/10/19 08:55:28 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

LIBFT_UTILS =	phi_atoi

UTILS =	error utils philo_lst_utils init_utils libft_utils sleep

SRCS =	main actions init

PHILO_SRCS =	${addsuffix .c, ${addprefix srcs/, ${SRCS}}} \
				${addsuffix .c, ${addprefix libft_utils/, ${LIBFT_UTILS}}} \
				${addsuffix .c, ${addprefix utils/, ${UTILS}}} \


PHILO_OBJS	=	${PHILO_SRCS:.c=.o}


PHI = philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

%.o: %.c
	@${CC} ${CFLAGS} ${RFLAGS} -c $< -o $@ 

all:			$(PHI)

$(PHI): $(PHILO_OBJS)
	@$(CC) $(CFLAGS) $(PHILO_OBJS) -lpthread -o $(PHI)
	@echo "${GREEN}philo executable ready!${RESET}"

clean:			
	@rm -f $(PHILO_OBJS)

fclean: clean
	@rm -f $(PHI)

allup : all clean

re:		fclean all

.PHONY:	all clean fclean allup re