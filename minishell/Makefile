# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/09 17:24:40 by ldelmas           #+#    #+#              #
#    Updated: 2021/08/19 14:07:12 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I includes/

RPATH = /Users/$(USER)/.brew/opt/readline/

RFLAGS = -L $(RPATH)lib -I $(RPATH)include -Wno-unused-command-line-argument

HEADER = minishell.h

MAIN = main

PIPE = exec command n_pipe builtins multifiles errors double_infile multiprocess

UTIL = basics cmd_lst str_lst env_utils str_utils basics2 main_utils

PARSE = parsing parsing_print parsing_basic_utils parsing_split parsing_utils check_line in_out_files get_next_word replace_by_env_value parsing_split_space

REBUILT = pwd echo env cd export unset exit

SIGNAL = signals

SRC =	${addsuffix .c, ${addprefix srcs/, ${MAIN}}} \
		${addsuffix .c, ${addprefix srcs/pipe/, ${PIPE}}} \
		${addsuffix .c, ${addprefix srcs/utils/, ${UTIL}}} \
		${addsuffix .c, ${addprefix srcs/parsing/, ${PARSE}}} \
		${addsuffix .c, ${addprefix srcs/rebuilt/, ${REBUILT}}} \
		${addsuffix .c, ${addprefix srcs/signals/, ${SIGNAL}}}

OBJ = ${SRC:c=o}

START = 0

%.o: %.c
	@${CC} ${CFLAGS} ${RFLAGS} -c $< -o $@ 
	
all : ${NAME}

${NAME}: ${OBJ}
	@echo "Minishell is compiling..."
	@${CC} ${CFLAGS} ${RFLAGS} -o ${NAME} ${OBJ} -lreadline
	@echo "Minishell is ready!"

clean :
	@echo "Removing binaries..."
	@rm -f ${OBJ}
	@echo "Binaries removed."

fclean : clean
	@echo "\nRemoving minishell executable..."
	@rm -f ${NAME}
	@echo "Minishell removed."

allup: all clean

re: clean all