# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/05/12 11:50:23 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)

PARSING_SRCS	=	parse_map.c \
					parse_map2.c \
					parse_lines.c \
					init.c \
					map_error.c \

PARSING_BONUS_SRCS	=	parse_map.c \
						parse_map2.c \
						parse_lines.c \
						init.c \
						map_error_bonus.c \

UTILS_SRCS =	free_and_return.c \
				free_split.c \
				free_struct.c \
				error.c \
				sprite_list.c \

UTILS_BONUS_SRCS =	free_and_return.c \
					free_split.c \
					free_struct.c \
					error.c \
					sprite_list.c \
					monster_list_bonus.c \

RAYCASTING_SRCS = 	init.c \
					images_init.c \
					distances.c \
					distances_utils.c \
					sprites.c \

RAYCASTING_BONUS_SRCS = init_bonus.c \
						init2_bonus.c \
						init3_bonus.c \
						images_init_bonus.c \
						images_init2_bonus.c \
						distances.c \
						distances_utils.c \
						sprites_bonus.c \
						sprites_utils_bonus.c \

MOVES_SRCS = 	keyboard_entry.c \
				next_frame.c \
				quit_credits.c \

MOVES_BONUS_SRCS = 	keyboard_entry.c \
					next_frame_bonus.c \
					next_frame_utils_bonus.c \
					next_frame_utils2_bonus.c \
					next_frame_utils3_bonus.c \
					quit_credits.c \

DRAW_SRCS = draw.c \
			draw2.c \
			game.c \

DRAW_BONUS_SRCS =	draw.c \
					draw2_bonus.c \
					draw3_bonus.c \
					game_bonus.c \
					game2_bonus.c \
					sky_bonus.c \
					minimap_bonus.c \
					minimap2_bonus.c \
					hud_bonus.c \

SAVE_SRCS = save_to_bmp.c \
			save_to_bmp_utils.c \

SRCS	=	cub3d.c \
			srcs/testing.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			$(addprefix srcs/parsing/, ${PARSING_SRCS}) \
			$(addprefix srcs/utils/, ${UTILS_SRCS}) \
			$(addprefix srcs/raycasting/, ${RAYCASTING_SRCS}) \
			$(addprefix srcs/moves/, ${MOVES_SRCS}) \
			$(addprefix srcs/drawing/, ${DRAW_SRCS}) \
			$(addprefix srcs/save/, ${SAVE_SRCS}) \

BONUS_SRCS	=	cub3d_bonus.c \
				srcs/testing.c \
				get_next_line/get_next_line_utils.c \
				get_next_line/get_next_line.c \
				$(addprefix srcs/parsing/, ${PARSING_BONUS_SRCS}) \
				$(addprefix srcs/utils/, ${UTILS_BONUS_SRCS}) \
				$(addprefix srcs/raycasting/, ${RAYCASTING_BONUS_SRCS}) \
				$(addprefix srcs/moves/, ${MOVES_BONUS_SRCS}) \
				$(addprefix srcs/drawing/, ${DRAW_BONUS_SRCS}) \
				$(addprefix srcs/save/, ${SAVE_SRCS}) \

LIBS = libmlx.a

OBJS	=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

LIGHT = -D LIGHT=1

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME	=	cub3D
LIBFT_NAME = libft.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft

all:			$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(SRCS) $(LIBS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}cub3d created${RESET}"

light:
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(LIGHT) $(SRCS) $(LIBS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}cub3d bonus created${RESET}"

bonus:
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(BONUS_SRCS) $(LIBS) $(LIBFT_PATH)/$(LIBFT_NAME) -D BONUS=1 -o $(NAME)
	@echo "${GREEN}cub3d bonus created${RESET}"

clean:			
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_PATH)

fclean:
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean allup re rebonus