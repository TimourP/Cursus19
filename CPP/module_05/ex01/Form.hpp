/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:59:32 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 17:14:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

# include <string>
# include <iostream>

class Form {
public:
	Form( void );
	Form( std::string const name, int const grade_to_sign, int const grade_to_exec);
	~Form( void );
	Form( Form const & copy );
	Form & operator=( Form const & rhs );

	std::string const getName( void ) const;
	bool const getIsSigned( void ) const;
	int const getGradeToSign( void ) const;
	int const getGradeToExec( void ) const;

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

private:
	std::string const _name;
	bool _is_signed;
	int const _grade_to_sign;
	int const _grade_to_exec;
};

std::ostream	&operator<<(std::ostream &out, const Form &in);

#endif // FORM_H
	