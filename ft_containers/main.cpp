/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/21 10:51:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewRedBlack.hpp"
#include "BinaryTree.hpp"
#include <unistd.h>
#include <time.h> 

int main(void)
{
	RedBlackTree rbt;
	std::string tmp;
	int value;

	while (tmp != "exit")
	{
		std::getline(std::cin, tmp);
		if (!tmp.empty() && tmp[0] == 'd') {
			value = std::atoi(tmp.substr(1).c_str());
			rbt.delete_node(value);
		}
		else {
			value = std::atoi(tmp.c_str());
			rbt.insert(value);
		}
		system("clear");
		rbt.print();
	}
	
}