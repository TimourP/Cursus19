/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:14:41 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/07 10:02:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_H
#define AANIMAL_H

#include <string>
#include <iostream>

class AAnimal
{
public:
	AAnimal(void);
	virtual ~AAnimal(void);
	AAnimal(AAnimal const &copy);
	AAnimal &operator=(AAnimal const &rhs);

	virtual void makeSound(void) const = 0;
	std::string getType(void) const;

protected:
	std::string _type;
};

#endif // AANIMAL_H
