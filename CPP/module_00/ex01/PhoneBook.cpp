/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:45:29 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/21 11:45:29 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contact_count = 0;
}

PhoneBook::~PhoneBook(void) {}

void PhoneBook::show_contacts(void)
{
	std::string line;
	std::string buff;

	for (size_t i = 0; i < this->_contact_count; i++)
	{
		buff = this->_contact_list[i].get_first_name();
		std::cout << buff << std::endl;
	}
}

void PhoneBook::add_contact(Contact new_contact)
{
	if (this->_contact_count < 8)
	{
		this->_contact_list[this->_contact_count] = new_contact;
		this->_contact_count++;
	}
	else
	{
		std::cout << "PhoneBook is full..." << std::endl;
	}
}