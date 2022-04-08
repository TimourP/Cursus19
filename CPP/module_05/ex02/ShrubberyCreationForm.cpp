/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:03 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 14:06:56 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("presidential pardon", "random target", 25, 5) {
	std::cout << "ShrubberyCreationForm is born" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("presidential pardon", target, 25, 5) {
	std::cout << "ShrubberyCreationForm is born" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "ShrubberyCreationForm is gone" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &to_copy ) : Form(to_copy.getName(), to_copy.getTarget(), 25, 5) {}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
	(void)rhs;
	return *this;
}

void ShrubberyCreationForm::execteAction(Bureaucrat const & executor) const {
	(void)executor;
	std::ofstream new_file;
		new_file.open(this->getTarget() + "_shrubbery");
		new_file << "               ,@@@@@@@," << std::endl;
		new_file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		new_file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		new_file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		new_file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		new_file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		new_file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		new_file << "       |o|        | |         | |" << std::endl;
		new_file << "       |.|        | |         | |" << std::endl;
		new_file << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
		new_file.close();
}
