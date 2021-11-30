/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:09:34 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 16:12:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
#define ICE_H

#include <string>
#include <iostream>
#include "AMateria.hpp"

class Ice : public virtual AMateria
{
public:
	Ice(void);
	~Ice(void);
	Ice(Ice const &copy);
	Ice &operator=(Ice const &rhs);

	AMateria *clone() const;
	void use(ICharacter &target);
};

#endif // ICE_H
