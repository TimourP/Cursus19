# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/03/02 10:57:08 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

PARSING_SRCS	=	parse_map.c \
					parse_map2.c \
					parse_lines.c \
					init.c \
					map_error.c \

UTILS_SRCS =	free_and_return.c \
				free_split.c \
				free_struct.c \

RAYCASTING_SRCS = init.c \

MOVES_SRCS = keyboard_entry.c \

DRAW_SRCS = draw.c \
			minimap.c \

SRCS	=	cub3d.c \
			srcs/testing.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			$(addprefix srcs/parsing/, ${PARSING_SRCS}) \
			$(addprefix srcs/utils/, ${UTILS_SRCS}) \
			$(addprefix srcs/raycasting/, ${RAYCASTING_SRCS}) \
			$(addprefix srcs/moves/, ${MOVES_SRCS}) \
			$(addprefix srcs/drawing/, ${DRAW_SRCS}) \

OBJS	=	${SRCS:.c=.o}			

NAME	=	cub3d.a
LIBFT_NAME = libft.a
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft

all:			$(NAME)

$(NAME):		$(OBJS)
	@make -C $(LIBFT_PATH)
	@ar -rcs $(NAME) $(OBJS)
	@$(CC) -lmlx -framework OpenGL -framework AppKit $(NAME) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "${GREEN}cub3d.a created${RESET}"

.c.o:
	@gcc $(CFLAG) -c -I./ $< -o ${<:.c=.o}

clean:			
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all clean

.PHONY:	all clean fclean allup re