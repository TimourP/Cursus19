/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:54 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 16:56:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Bob"), _grade(150) {
	std::cout << "Bureaucrat is born" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat is born" << std::endl;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat is gone" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &to_copy ) : _name(to_copy.getName()) {}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const & rhs ) {
	this->_grade = rhs.getGrade();
	return *this;
}


std::string Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return this->_grade;
}

void Bureaucrat::increaseGrade( void ) {
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decreaseGrade( void ) {
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &in)
{
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << ".";
	return out;
}
