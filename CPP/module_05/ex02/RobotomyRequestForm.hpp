/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:10 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 14:04:35 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public virtual Form {
	public:
		RobotomyRequestForm( void );
		~RobotomyRequestForm( void );
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( RobotomyRequestForm const & copy );
		RobotomyRequestForm & operator=( RobotomyRequestForm const & rhs );

		void execute(Bureaucrat const & executor) const;
	
	private:

};

std::ostream	&operator<<(std::ostream &out, const RobotomyRequestForm &in);

#endif // ROBOTOMYREQUESTFORM_H
	