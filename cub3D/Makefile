# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/02/25 13:35:06 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

PARSING_SRCS	=	parse_map.c \
					parse_lines.c \
					init.c \

UTILS_SRCS =	free_and_return.c \
				free_split.c \

SRCS	=	cub3d.c \
			srcs/testing.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			$(addprefix srcs/parsing/, ${PARSING_SRCS}) \
			$(addprefix srcs/utils/, ${UTILS_SRCS}) \

OBJS	=	${SRCS:.c=.o}			

NAME	=	cub3d.a
LIBFT_NAME = libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft

all:			$(NAME)

$(NAME):		$(OBJS)
	@make -C $(LIBFT_PATH)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "${GREEN}cub3d.a created${RESET}"

clean:			
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all

.PHONY:	all clean fclean allup re