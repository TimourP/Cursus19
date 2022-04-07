/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:44 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/07 10:03:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include <string>
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public virtual AAnimal
{
public:
	Dog(void);
	~Dog(void);
	Dog(Dog const &copy);
	Dog &operator=(Dog const &rhs);

	void makeSound(void) const;
	Brain *getBrain(void) const;

private:
	Brain *_brain;
};

#endif // DOG_H
