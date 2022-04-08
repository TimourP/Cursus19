/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:32 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 13:58:38 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : _name("FormToForm"), _is_signed(false),  _grade_to_sign(150), _grade_to_exec(150) {
	std::cout << "Form is born" << std::endl;
}

Form::Form( std::string const name, int const grade_to_sign, int const grade_to_exec ) : _name(name), _is_signed(false),  _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec) {
	std::cout << "Form is born" << std::endl;
}

Form::~Form( void ) {
	std::cout << "Form is gone" << std::endl;
}

Form::Form( Form const &to_copy ) : _name(to_copy.getName()), _is_signed(to_copy.getIsSigned()),  _grade_to_sign(to_copy.getGradeToSign()), _grade_to_exec(to_copy.getGradeToExec()){}

Form	&Form::operator=( Form const & rhs ) {
	this->_is_signed = rhs.getIsSigned();
	return *this;
}

std::string Form::getName( void ) const {
	return this->_name;
}

bool Form::getIsSigned( void ) const {
	return this->_is_signed;
}

int Form::getGradeToSign( void ) const {
	return this->_grade_to_sign;
}

int Form::getGradeToExec( void ) const {
	return this->_grade_to_exec;
}

void Form::beSigned( Bureaucrat const &b ) {
	if (b.getGrade() <= this->_grade_to_sign) {
		this->_is_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

std::ostream	&operator<<(std::ostream &out, const Form &in)
{
	out << in.getName() << ", form is signed: " << in.getIsSigned() << ", grade to sign: " << in.getGradeToSign() << ", grade to exec: " << in.getGradeToExec() << ".";
	return out;
}