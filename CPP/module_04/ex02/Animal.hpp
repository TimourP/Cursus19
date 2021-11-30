/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:59:58 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal
{
public:
	Animal(void);
	virtual ~Animal(void);
	Animal(Animal const &copy);
	Animal &operator=(Animal const &rhs);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;

protected:
	std::string _type;
};

#endif // ANIMAL_H
