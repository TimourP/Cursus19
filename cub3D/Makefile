# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/04/20 10:43:16 by tpetit           ###   ########.fr        #
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
				error.c \
				sprite_list.c \

RAYCASTING_SRCS = 	init.c \
					images_init.c \
					distances.c \
					distances_utils.c \
					sprites.c \

MOVES_SRCS = 	keyboard_entry.c \
				next_frame.c \

DRAW_SRCS = draw.c \
			draw2.c \
			game.c \
			sky.c \
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

BONUS = -D BONUS=1
LIGHT = -D LIGHT=1

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME	=	cub3D
LIBFT_NAME = libft.a
CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
LIBFT_PATH	=	./libft

all:			$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}cub3d created${RESET}"

light:
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(LIGHT) $(SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}cub3d bonus created${RESET}"

bonus:
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(BONUS) $(SRCS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}cub3d bonus created${RESET}"

clean:			
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean allup re rebonus