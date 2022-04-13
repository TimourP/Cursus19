/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/13 17:11:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "BinaryTree.hpp"

int main(void)
{
	RedBlackTree rbt;
	int *test;

	for (size_t i = 1; i <= 60000; i++)
	{
		rbt.insert(i);
	}
	for (size_t i = 0; i < 10000; i++)
	{
		rbt.search(59999)->key;
		std::cout << i << std::endl;
	}
}