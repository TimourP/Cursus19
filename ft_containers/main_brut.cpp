/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_brut.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:26:27 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/26 13:27:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewRedBlack.hpp"
#include "BinaryTree.hpp"
#include <unistd.h>
#include <time.h> 

int main(void)
{
	RedBlackTree rbt;
	BinaryTree bt;

	srand (time(NULL));

	for (size_t i = 0; i < 5000; i++)
	{
		rbt.insert(rand() % 10 + 1);
	}
	rbt.print();
}