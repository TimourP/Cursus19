/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:39:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:13:17 by tpetit           ###   ########.fr       */
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
	p_f->execute(*bob);

	bob->signForm(*r_r);
	r_r->execute(*bob);

	bob->signForm(*s_r);
	s_r->execute(*bob);

	delete bob;
	delete p_f;
	delete r_r;
	delete s_r;
}