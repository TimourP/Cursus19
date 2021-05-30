# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 15:32:17 by tpetit            #+#    #+#              #
#    Updated: 2021/05/30 08:47:22 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UTILS_SRCS =	error.c \

SERVER_SRCS = 	server.c \

CLIENT_SRCS = client.c \

ALL_SERVER_SRCS =	$(addprefix server_srcs/, ${SERVER_SRCS}) \
					$(addprefix utils/, ${UTILS_SRCS}) \

ALL_CLIENT_SRCS =	$(addprefix client_srcs/, ${CLIENT_SRCS}) \
					$(addprefix utils/, ${UTILS_SRCS}) \

SERVER_OBJS	=	${ALL_SERVER_SRCS:.c=.o}
CLIENT_OBJS	=	${ALL_CLIENT_SRCS:.c=.o}

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