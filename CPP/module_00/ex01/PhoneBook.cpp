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

void out_and_trim(std::string buff)
{
	const std::string spaces = "          ";

	if (buff.length() > 10)
		std::cout << buff.substr(0, 9) << ".";
	else
		std::cout << spaces.substr(0, 10 - buff.length()) << buff;
}

void PhoneBook::show_contacts(void)
{
	std::string line;
	std::string buff;
	int id;

	std::cout << "     index|first name| last name|  nickname" << std::endl;

	for (int i = 0; i < this->_contact_count; i++)
	{
		buff = std::to_string(i);
		out_and_trim(buff);
		std::cout << "|";

		buff = this->_contact_list[i].get_first_name();
		out_and_trim(buff);
		std::cout << "|";

		buff = this->_contact_list[i].get_last_name();
		out_and_trim(buff);
		std::cout << "|";

		buff = this->_contact_list[i].get_nickname();
		out_and_trim(buff);
		std::cout << std::endl;
	}

	std::cout << "Please enter the contact id: ";
	std::getline(std::cin, buff);
	id = std::stoi(buff);
	if (id < 0 || id >= this->_contact_count)
		std::cout << "I'm just a phone book that sucks. Don't be too mean to me." << std::endl;
	else
	{
		std::cout << "First name: " << this->_contact_list[id].get_first_name() << std::endl;
		std::cout << "Last name: " << this->_contact_list[id].get_last_name() << std::endl;
		std::cout << "Nickname: " << this->_contact_list[id].get_nickname() << std::endl;
		std::cout << "Phone number: " << this->_contact_list[id].get_phone_number() << std::endl;
		std::cout << "Darkest secret: " << this->_contact_list[id].get_darkest_secret() << std::endl;
	}
}

void PhoneBook::add_contact(void)
{
	if (this->_contact_count < 7)
	{
		this->_contact_count++;
	}
	else
	{
		std::cout << "PhoneBook is full..." << std::endl;
	}
}

Contact *PhoneBook::get_contact(void)
{
	return (&this->_contact_list[this->_contact_count]);
}