/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTreeMain.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:48 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/03 12:41:34 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(void)
{
	
	ft::RBTree<int, int, ft::less<int> > rbt;
	ft::pair<int, int> test;

	srand(time(NULL));

	for (size_t i = 0; i < 10; i++)
	{
		ft::pair<int, int> p(rand() % 100 + 1, 3);
		if (i == 1) {
			std::cout << p.first << std::endl;
			test = p;
		}
		rbt.insert(p);
	}
	rbt.unAttachEnd();
	std::cout << "-------" << std::endl;
	rbt.print();
	rbt.deleteByKey(test);
	rbt.print();
	rbt.attachEnd();
}