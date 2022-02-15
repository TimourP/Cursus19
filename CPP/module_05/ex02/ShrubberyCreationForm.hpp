/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:03 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:29:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <fstream>


class ShrubberyCreationForm : public virtual Form {
	public:
		ShrubberyCreationForm( void );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & copy );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & rhs );
	
		void execute(Bureaucrat const & executor) const;
	private:

};

std::ostream	&operator<<(std::ostream &out, const ShrubberyCreationForm &in);

#endif // SHRUBBERYCREATIONFORM_H
	