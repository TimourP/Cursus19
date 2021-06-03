# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 15:32:17 by tpetit            #+#    #+#              #
#    Updated: 2021/06/03 14:02:49 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS_SRCS =	error.c \
				libft.c \

SERVER_SRCS = 	server.c \

SERVER_BONUS_SRCS =	server_bonus.c \
					server_utils_bonus.c \

CLIENT_SRCS = 	client.c \
				client_utils.c \

CLIENT_BONUS_SRCS =	client_bonus.c \
					client_utils.c \

ALL_SERVER_SRCS =	$(addprefix server_srcs/, ${SERVER_SRCS}) \
					$(addprefix utils/, ${UTILS_SRCS}) \

ALL_CLIENT_SRCS =	$(addprefix client_srcs/, ${CLIENT_SRCS}) \
					$(addprefix utils/, ${UTILS_SRCS}) \

ALL_SERVER_BONUS_SRCS =	$(addprefix server_srcs/, ${SERVER_BONUS_SRCS}) \
						$(addprefix utils/, ${UTILS_SRCS}) \

ALL_CLIENT_BONUS_SRCS =	$(addprefix client_srcs/, ${CLIENT_BONUS_SRCS}) \
						$(addprefix utils/, ${UTILS_SRCS}) \

SERVER_OBJS	=	${ALL_SERVER_SRCS:.c=.o}
SERVER_BONUS_OBJS = ${ALL_SERVER_BONUS_SRCS:.c=.o}
CLIENT_OBJS	=	${ALL_CLIENT_SRCS:.c=.o}
CLIENT_BONUS_OBJS = ${ALL_CLIENT_BONUS_SRCS:.c=.o}

SERVER	=	server
CLIENT = client
CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
LIBFT_NAME = libft.a
LIBFT_PATH	=	./libft

all:	$(SERVER)

$(SERVER):
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(ALL_SERVER_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(SERVER)

$(CLIENT):
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(ALL_CLIENT_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(CLIENT)

both:
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(ALL_SERVER_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(SERVER)
	@$(CC) $(CFLAGS) $(ALL_CLIENT_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(CLIENT)

both_bonus:
	@make -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(ALL_SERVER_BONUS_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(SERVER)
	@$(CC) $(CFLAGS) $(ALL_CLIENT_BONUS_SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(CLIENT)

clean:
	@rm -f $(SWAP_OBJS)
	@rm -f $(SWAP_OBJS)

fclean: clean
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all

re_client: fclean client

.PHONY:	all clean fclean allup re re_client