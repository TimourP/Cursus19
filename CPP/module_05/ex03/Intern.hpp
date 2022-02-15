/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:53:09 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 15:53:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_H
# define INTERN_H

# include <string>
# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

Form *createPresidentialForm (std::string target) {
	Form * new_form = new PresidentialPardonForm(target);
	std::cout << "Intern creates " << *new_form << std::endl;
	return new_form;
}

Form *createRobotomyForm (std::string target) {
	Form * new_form = new RobotomyRequestForm(target);
	std::cout << "Intern creates " << *new_form << std::endl;
	return new_form;
}

Form *createShrubberyForm (std::string target) {
	Form * new_form = new ShrubberyCreationForm(target);
	std::cout << "Intern creates " << *new_form << std::endl;
	return new_form;
}

typedef struct s_form_dict {
	std::string key;
	Form *(*form_ptr)(std::string const target);
}		t_form_dict;

const t_form_dict f_dict[3] = {
	{"presidential pardon", &createPresidentialForm},
	{"robotomy request", &createRobotomyForm},
	{"shrubbery creation", &createShrubberyForm},
};

class Intern {
	public:
		Intern( void ){};
		~Intern( void ){};
		Intern( Intern const & copy ){};
		Intern & operator=( Intern const & rhs ){
			return *this;
		};

		Form *makeForm( std::string form_name, std::string target) const {
			for (size_t i = 0; i < 3; i++)
				if (f_dict[i].key == form_name)
					return (f_dict[i].form_ptr(target));
			std::cout << "I can't make that" << std::endl;
			return NULL;
		};

};

#endif // INTERN_H
