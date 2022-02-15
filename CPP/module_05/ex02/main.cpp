/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:48:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
	Bureaucrat *bob = new Bureaucrat("bob", 1);
	Form *p_f = new PresidentialPardonForm("bob the target");
	Form *r_r = new RobotomyRequestForm("bob the target");
	Form *s_r = new ShrubberyCreationForm("bob the target");

	std::cout << *p_f << std::endl;
	try
	{
		p_f->execute(*bob);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	bob->signForm(*p_f);
	bob->executeForm(*p_f);

	bob->signForm(*r_r);
	bob->executeForm(*r_r);

	bob->signForm(*s_r);
	bob->executeForm(*s_r);

	delete bob;
	delete p_f;
	delete r_r;
	delete s_r;
}