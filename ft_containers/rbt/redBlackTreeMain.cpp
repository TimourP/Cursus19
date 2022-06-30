/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redBlackTreeMain.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:53:48 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/30 16:55:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>

int main(void)
{
	ft::RBTree<int, int> rb;

	for (size_t i = 0; i < 10; i++)
	{
		ft::pair<int, int> p(i, 3);
		rb.insert(p);
		rb.print();
	}
	
	rb.print();
}