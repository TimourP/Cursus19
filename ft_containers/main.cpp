/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/13 21:03:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include "BinaryTree.hpp"
#include <unistd.h>

#include <random>

constexpr int MIN = 1;
constexpr int MAX = 250;

constexpr int RAND_NUMS_TO_GENERATE = 10;

int main(void)
{
	RedBlackTree rbt;
	BinaryTree bt;
	int *test;
	int val;

	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution<int> distr(MIN, MAX);

	for (size_t i = 0; i < 20; i++)
	{
		val = distr(eng);
		while (rbt.search(val))
		{
			val = distr(eng);
		}

		rbt.insert(val);
		// system("clear");
		// rbt.print();
		// usleep(50000);
	}
	rbt.print();
}