/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:15:47 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/21 11:15:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <cstring>

class PhoneBook
{
public:
	PhoneBook(void);
	~PhoneBook(void);

	void show_contacts(void);
	void add_contact(Contact new_contact);

private:
	Contact _contact_list[8];
	int _contact_count;
};

#endif