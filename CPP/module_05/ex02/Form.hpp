/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:32 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:46:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form( void );
	Form( std::string const name, std::string const target, int const grade_to_sign, int const grade_to_exec);
	virtual ~Form( void );
	Form( Form const & copy );
	Form & operator=( Form const & rhs );

	std::string getName( void ) const;
	bool getIsSigned( void ) const;
	int getGradeToSign( void ) const;
	int getGradeToExec( void ) const;
	std::string getTarget( void ) const;

	virtual void execteAction(Bureaucrat const & executor) const = 0;
	void execute(Bureaucrat const & executor) const;

	void beSigned( Bureaucrat const &b );

	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too high. Max grade is 1.";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "Grade is too low. Min grade is 150.";
			}
	};

	class NotEvenSignedException : public std::exception {
		public:
			virtual const char* what() const throw() {
				return "This form is not even signed. Please signe it before execute it.";
			}
	};

private:
	std::string const _name;
	bool _is_signed;
	int const _grade_to_sign;
	int const _grade_to_exec;
	std::string const _target;
};

std::ostream	&operator<<(std::ostream &out, const Form &in);

#endif // FORM_H
	