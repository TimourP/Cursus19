/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 11:11:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat *b = new Bureaucrat("Bob", 1);
	Form *f = new Form("main_form", 5, 5);
	std::cout << *b << std::endl;
	
	try
	{
		b->increaseGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	b->decreaseGrade();

	b->signForm(*f);
	delete f;
	f = new Form("main_form", 1, 1);;
	b->signForm(*f);
	std::cout << *b << std::endl;
	delete f;
	delete b;
}