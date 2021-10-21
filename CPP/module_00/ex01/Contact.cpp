/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 11:38:52 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/21 11:38:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::set_first_name(const std::string first_name)
{
	this->_first_name = first_name;
}

void Contact::set_last_name(const std::string last_name)
{
	this->_last_name = last_name;
}

void Contact::set_nickname(const std::string nickname)
{
	this->_nickname = nickname;
}

void Contact::set_phone_number(const std::string phone_number)
{
	this->_phone_number = phone_number;
}

void Contact::set_darkest_secret(const std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string Contact::get_first_name(void) const
{
	return (this->_first_name);
}

std::string Contact::get_last_name(void) const
{
	return (this->_last_name);
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

std::string Contact::get_phone_number(void) const
{
	return (this->_phone_number);
}

std::string Contact::get_darkest_secret(void) const
{
	return (this->_darkest_secret);
}