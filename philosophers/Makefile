# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 18:13:02 by tpetit            #+#    #+#              #
#    Updated: 2021/06/08 16:28:24 by tpetit           ###   ########.fr        #
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

PHILO_ONE =	main.c \
			actions.c \

PHILO_TWO =	main.c \

PHILO_THREE =	main.c \

PHILO_ONE_SRCS =	$(addprefix utils/, ${UTILS_SRCS}) \
					$(addprefix phi1_srcs/, ${PHILO_ONE}) \
					$(addprefix libft_utils/, ${LIBFT_UTILS}) \

PHILO_TWO_SRCS =	$(addprefix utils/, ${UTILS_SRCS}) \
					$(addprefix phi2_srcs/, ${PHILO_TWO}) \
					$(addprefix libft_utils/, ${LIBFT_UTILS}) \

PHILO_THREE_SRCS =	$(addprefix utils/, ${UTILS_SRCS}) \
					$(addprefix phi3_srcs/, ${PHILO_THREE}) \
					$(addprefix libft_utils/, ${LIBFT_UTILS}) \

PHILO_ONE_OBJS	=	${PHILO_ONE_SRCS:.c=.o}
PHILO_TWO_OBJS	=	${PHILO_TWO_SRCS:.c=.o}
PHILO_THREE_OBJS =	${PHILO_THREE_SRCS:.c=.o}

PHI1 = philo_one
PHI2 = philo_two
PHI3 = philo_three
CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror

all:			$(NAME) $(CHECK_NAME)

$(PHI1): $(PHILO_ONE_OBJS)
	@$(CC) $(CFLAGS) $(PHILO_ONE_OBJS) -lpthread -o $(PHI1)
	@echo "${GREEN}philo_one executable ready!${RESET}"

$(PHI2): $(PHILO_TWO_OBJS)
	@$(CC) $(CFLAGS) $(PHILO_TWO_OBJS) -lpthread -o $(PHI2)
	@echo "${GREEN}philo_two executable ready!${RESET}"

$(PHI3): $(PHILO_THREE_OBJS)
	@$(CC) $(CFLAGS) $(PHILO_THREE_OBJS) -lpthread -o $(PHI3)
	@echo "${GREEN}philo_three executable ready!${RESET}"

clean:			
	@rm -f $(PHILO_ONE_OBJS)
	@rm -f $(PHILO_TWO_OBJS)
	@rm -f $(PHILO_THREE_OBJS)

fclean: clean
	@rm -f $(PHI1)
	@rm -f $(PHI2)
	@rm -f $(PHI3)

allup : all clean

re:		fclean all

.PHONY:	all clean fclean allup re