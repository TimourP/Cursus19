/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 14:40:41 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *b = new Bureaucrat("Bob", 1);
	Bureaucrat *new_b = new Bureaucrat("NewBob", 150);
	try
	{
		Bureaucrat *wrong_b = new Bureaucrat("WrongBob", 1200);
		std::cout << *wrong_b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << *b << std::endl;
	std::cout << *new_b << std::endl;
	
	try
	{
		b->increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		new_b->decreaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	b->decreaseGrade();
	std::cout << *b << std::endl;
	delete b;
	delete new_b;
}