/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_brut.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/25 18:57:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rbt/NewRedBlack.hpp"
#include "rbt/BinaryTree.hpp"
#include <unistd.h>
#include <time.h>

int main(void)
{
	RedBlackTree rbt;
	BinaryTree bt;

	srand(time(NULL));

	for (size_t i = 0; i < 50000; i++)
	{
		rbt.insert(rand() % 100 + 1);
	}
	rbt.print();
}