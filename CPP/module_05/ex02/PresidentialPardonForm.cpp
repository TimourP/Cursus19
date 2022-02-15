/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:17 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:45:46 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : Form("presidential pardon", "random target", 25, 5) {
	std::cout << "PresidentialPardonForm is born" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("presidential pardon", target, 25, 5) {
	std::cout << "PresidentialPardonForm is born" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "PresidentialPardonForm is gone" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &to_copy ) : Form(to_copy.getName(), to_copy.getTarget(), 25, 5) {
	std::cout << "PresidentialPardonForm is born" << std::endl;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
	return *this;
}

void PresidentialPardonForm::execteAction(Bureaucrat const & executor) const {
	std::cout << this->getTarget() << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}
