# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:13:02 by tpetit            #+#    #+#              #
#    Updated: 2021/08/19 14:08:08 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 11:29:13 by tpetit            #+#    #+#              #
#    Updated: 2021/06/07 15:59:35 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

LIBFT_UTILS =	phi_atoi.c \

UTILS_SRCS =	error.c \
				utils.c \
				philo_lst_utils.c \

PHILO_ONE =	main.c \
			actions.c \
			init.c \

PHILO_SRCS =	$(addprefix utils/, ${UTILS_SRCS}) \
					$(addprefix phi1_srcs/, ${PHILO_ONE}) \
					$(addprefix libft_utils/, ${LIBFT_UTILS}) \


PHILO_OBJS	=	${PHILO_SRCS:.c=.o}


PHI = philo
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

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