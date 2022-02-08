/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:54:50 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 13:57:18 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <string>
# include <iostream>

class WrongAnimal {
public:
	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(WrongAnimal const &copy);
	WrongAnimal &operator=(WrongAnimal const &rhs);

	void makeSound(void) const;
	std::string getType(void) const;

protected:
	std::string _type;

};

#endif // WRONGANIMAL_H
	