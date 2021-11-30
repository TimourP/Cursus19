/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:46 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:07:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include <string>
#include <iostream>
#include "Animal.hpp"

class Cat : public virtual Animal
{
public:
	Cat(void);
	~Cat(void);
	Cat(Cat const &copy);
	Cat &operator=(Cat const &rhs);

	void makeSound(void) const;
};

#endif // CAT_H
