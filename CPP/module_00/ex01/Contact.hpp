/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:22:47 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/21 11:22:47 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact
{
public:
	Contact(void);
	~Contact(void);
	std::string get_first_name(void) const;
	std::string get_last_name(void) const;
	std::string get_nickname(void) const;
	std::string get_phone_number(void) const;
	std::string get_darkest_secret(void) const;

	void set_first_name(const std::string first_name);
	void set_last_name(const std::string last_name);
	void set_nickname(const std::string nickname);
	void set_phone_number(const std::string phone_number);
	void set_darkest_secret(const std::string darkest_secret);

private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif