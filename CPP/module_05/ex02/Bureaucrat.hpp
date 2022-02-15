/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:21:54 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 11:09:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
# define BUREAUCRAT_H

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	~Bureaucrat( void );
	Bureaucrat( Bureaucrat const & copy );
	Bureaucrat & operator=( Bureaucrat const & rhs );

	std::string getName( void ) const;

	int getGrade( void ) const;
	void increaseGrade( void );
	void decreaseGrade( void );

	void signForm( Form &f ) const;

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
	int _grade;
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &in);

#endif // BUREAUCRAT_H
	