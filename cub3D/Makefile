# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 14:30:14 by tpetit            #+#    #+#              #
#    Updated: 2021/02/24 20:06:53 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PARSING_SRCS	=	parse_map.c

SRCS	=	cub3d.c \
			get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			$(addprefix srcs/parsing/, ${PARSING_SRCS}) \

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

clean:			
				@rm -f $(OBJS)
				@make clean -C $(LIBFT_PATH)

fclean:
				@rm -f $(OBJS)
				@rm -f $(NAME)
				@make fclean -C $(LIBFT_PATH)

allup : all clean

re:				fclean all

.PHONY:			all clean fclean allup re