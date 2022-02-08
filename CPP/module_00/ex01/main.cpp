/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:40:36 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/21 11:40:36 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main( void )
{
	PhoneBook phone_book;
	std::string tmp;
	Contact *contact;

	while (1)
	{
		std::cout << "Please write a command (EXIT, ADD or SEARCH): ";
		std::getline(std::cin, tmp);
		if (tmp == "EXIT")
			break;
		else if (tmp == "ADD")
		{
			contact = phone_book.get_contact();
			std::cout << "In order to create a new contact we need some information" << std::endl;
			std::cout << "First name: ";
			std::getline(std::cin, tmp);
			contact->set_first_name(tmp);
			std::cout << "Last name: ";
			std::getline(std::cin, tmp);
			contact->set_last_name(tmp);
			std::cout << "Nickname: ";
			std::getline(std::cin, tmp);
			contact->set_nickname(tmp);
			std::cout << "Phone number: ";
			std::getline(std::cin, tmp);
			contact->set_phone_number(tmp);
			std::cout << "Darkest secret: ";
			std::getline(std::cin, tmp);
			contact->set_darkest_secret(tmp);
			phone_book.add_contact();
		}
		else if (tmp == "SEARCH")
			phone_book.show_contacts();
	}

	return (0);
}