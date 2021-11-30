/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:03:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:18:10 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_H
#define AMATERIA_H

#include <string>
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria(void);
	virtual ~AMateria(void);
	AMateria(AMateria const &copy);
	AMateria &operator=(AMateria const &rhs);

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);

protected:
	std::string _type;
};

#endif // AMATERIA_H
