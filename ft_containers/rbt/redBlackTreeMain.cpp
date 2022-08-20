/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTreeMain.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:48 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/20 17:15:55 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(void)
{
	
	ft::RBTree<int, int, ft::more<int>> rbt;

	srand(time(NULL));

	for (size_t i = 0; i < 10; i++)
	{
		ft::pair<int, int> p(rand() % 100 + 1, 3);
		rbt.insert(p);
	}
	rbt.print();
}