/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:19:51 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/08 14:52:49 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_H
#define MATERIASOURCE_H

#include <string>
#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public virtual IMateriaSource
{
public:
	MateriaSource(void);
	~MateriaSource(void);
	MateriaSource(MateriaSource const &copy);
	MateriaSource &operator=(MateriaSource const &rhs);

	void learnMateria(AMateria * materia);
	AMateria *createMateria(std::string const &type);

private:
	AMateria *_inventory[4];
};

#endif // MATERIASOURCE_H
