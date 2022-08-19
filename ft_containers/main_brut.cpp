/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_brut.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2022/08/19 20:29:20 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt/RedBlackTree.hpp"
#include <unistd.h>
#include <time.h>

int main(void)
{
	RBTree rbt;

	srand(time(NULL));

	for (size_t i = 0; i < 50000; i++)
	{
		rbt.insert(rand() % 100 + 1);
	}
	rbt.print();
}