/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:09:37 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 15:46:28 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
#define CURE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Cure : public virtual AMateria
{
public:
	Cure(void);
	~Cure(void);
	Cure(Cure const &copy);
	Cure &operator=(Cure const &rhs);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif // CURE_H
