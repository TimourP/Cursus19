# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 12:26:52 by tpetit            #+#    #+#              #
#    Updated: 2021/11/30 12:28:55 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CPPFLAGS = -Wall -Wextra -Werror

SRCS = main.cpp DiamondTrap.cpp ScavTrap.cpp ClapTrap.cpp FragTrap.cpp

NAME = scav_trap

all:
	g++ $(CPPFLAGS) $(SRCS) -o $(NAME)
	
clean:
	rm $(NAME)