# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/05/19 11:29:49 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		= $(shell tput -Txterm setaf 2)
RESET		= $(shell tput -Txterm sgr0)


UTILS_SRCS =	error.c \
				init.c \

FRACTALS_SRCS =	mandelbrot.c \

DRAW_SRCS = draw.c \

FRAMES_SRCS = 	frames.c \
				moves.c \

SRCS	=	fractol.c \
			$(addprefix srcs/utils/, ${UTILS_SRCS}) \
			$(addprefix srcs/draw/, ${DRAW_SRCS}) \
			$(addprefix srcs/frames/, ${FRAMES_SRCS}) \
			$(addprefix srcs/fractals/, ${FRACTALS_SRCS}) \

LIBS = libmlx.a

OBJS	=	${SRCS:.c=.o}

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