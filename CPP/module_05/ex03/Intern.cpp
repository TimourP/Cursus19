
#include "Intern.hpp"

Intern::Intern( void )  {
	std::cout << "Intern is born" << std::endl;
}

Intern::~Intern( void ) {
	std::cout << "Intern is gone" << std::endl;
}

Intern::Intern( Intern const &to_copy ) {
	(void)to_copy;
}

Intern	&Intern::operator=( Intern const & rhs ) {
	(void)rhs;
	return *this;
}


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

Form *Intern::makeForm( std::string form_name, std::string target) const {
	for (size_t i = 0; i < 3; i++)
		if (f_dict[i].key == form_name)
			return (f_dict[i].form_ptr(target));
	std::cout << "I can't make that" << std::endl;
	return NULL;
};