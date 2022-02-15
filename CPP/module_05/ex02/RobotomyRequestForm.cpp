/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:45:39 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <time.h>  

RobotomyRequestForm::RobotomyRequestForm( void ) : Form("robotomy request", "random target", 72, 45) {
	std::cout << "RobotomyRequestForm is born" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("robotomy request", target, 72, 45) {
	std::cout << "RobotomyRequestForm is born" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "RobotomyRequestForm is gone" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &to_copy ) : Form(to_copy.getName(), to_copy.getTarget(), 72, 45) {
	std::cout << "RobotomyRequestForm is born" << std::endl;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	return *this;
}

void RobotomyRequestForm::execteAction(Bureaucrat const & executor) const {
	std::srand (time(NULL));
	std::cout << "Brouoouououou je suis un bruit de perceuse!! ";
	if (std::rand() % 2)
		std::cout << this->getTarget() << " a été robotomisée avec succès!" << std::endl;
	else
		std::cout << this->getTarget() << " n'a pas été robotomisée. Erreur." << std::endl;
}
