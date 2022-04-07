/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/07 10:03:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public virtual AAnimal
{
public:
	Cat(void);
	~Cat(void);
	Cat(Cat const &copy);
	Cat &operator=(Cat const &rhs);

	void makeSound(void) const;
	Brain *getBrain(void) const;

private:
	Brain *_brain;
};

#endif // CAT_H
