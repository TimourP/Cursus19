/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:20:17 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 12:22:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_H
# define PRESIDENTIALPARDONFORM_H

# include <string>
# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public virtual Form {
	public:
		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string target );
		~PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const & copy );
		PresidentialPardonForm & operator=( PresidentialPardonForm const & rhs );
	
		void execute(Bureaucrat const & executor) const;
	private:

};


#endif // PRESIDENTIALPARDONFORM_H
	