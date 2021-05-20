# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/05/20 14:33:27 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)


UTILS_SRCS =	error.c \
				init.c \

BONUS_UTILS_SRCS =	error.c \
					init.c \

FRACTALS_SRCS =	mandelbrot.c \
				julia.c \

BONUS_FRACTALS_SRCS =	mandelbrot_bonus.c \
						julia_bonus.c \

DRAW_SRCS = draw.c \

FRAMES_SRCS = 	frames.c \
				moves.c \

BONUS_FRAMES_SRCS = 	frames_bonus.c \
						moves.c \

SRCS	=	fractol.c \
			$(addprefix srcs/utils/, ${UTILS_SRCS}) \
			$(addprefix srcs/draw/, ${DRAW_SRCS}) \
			$(addprefix srcs/frames/, ${FRAMES_SRCS}) \
			$(addprefix srcs/fractals/, ${FRACTALS_SRCS}) \

BONUS_SRCS	=	fractol.c \
				$(addprefix srcs/utils/, ${BONUS_UTILS_SRCS}) \
				$(addprefix srcs/draw/, ${DRAW_SRCS}) \
				$(addprefix srcs/frames/, ${BONUS_FRAMES_SRCS}) \
				$(addprefix srcs/fractals/, ${BONUS_FRACTALS_SRCS}) \

LIBS = libmlx.a

OBJS	=	${SRCS:.c=.o}
BONUS_OBJS	=	${BONUS_SRCS:.c=.o}

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME	=	fractol
LIBFT_NAME = libft.a
CC		=	gcc
CFLAGS	=	#-Wall -Wextra -Werror
LIBFT_PATH	=	./libft

all:			$(NAME)

$(NAME):
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(SRCS) $(LIBS) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME)
	@echo "${GREEN}fractol created${RESET}"

bonus:
	@make -C $(LIBFT_PATH)
	@$(CC) $(MLX_FLAGS) $(CFLAGS) $(BONUS_SRCS) $(LIBS) $(LIBFT_PATH)/$(LIBFT_NAME) -lpthread -o $(NAME)
	@echo "${GREEN}fractol created${RESET}"

clean:			
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@make clean -C $(LIBFT_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)

allup : all clean

re:		fclean all

rebonus: fclean bonus

.PHONY:	all clean fclean allup re bonus rebonus