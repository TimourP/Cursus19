/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTreeMain.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:48 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/29 14:42:17 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(void)
{

	ft::RBTree<int, int> rb;
	srand(time(0));
	srand(time(NULL));

	for (size_t i = 0; i < 100; i++)
	{
		ft::RBTree<int, int>::value_type value(rand() % 1000 + 1, 0);
		rb.insert(value);
	}
	rb.print();
}