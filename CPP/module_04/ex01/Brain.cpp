/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:16:51 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:45:24 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) : _idea_index(0)
{
	std::cout << "Hmmm it seems that a new consciousness is born..." << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "By consciousness..." << std::endl;
}

Brain::Brain(Brain const &to_copy) {}

Brain &Brain::operator=(Brain const &rhs)
{
	return *this;
}

std::string Brain::getIdea(int index) const
{
	if (index > 0 && index < 100)
		return this->_ideas[index];
	return this->_ideas[0];
}

void Brain::haveIdea(std::string idea)
{
	this->_ideas[this->_idea_index] = idea;
	if (this->_idea_index == 99)
		this->_idea_index = 0;
	else
		this->_idea_index++;
}
