/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:07:01 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 08:33:21 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

ScalarConversion::ScalarConversion(void) : _value("0") {}

ScalarConversion::ScalarConversion(std::string const initial_value) : _value(initial_value) {}

ScalarConversion::~ScalarConversion(void) {}

ScalarConversion::ScalarConversion(ScalarConversion const &to_copy) {}

ScalarConversion &ScalarConversion::operator=(ScalarConversion const &rhs)
{
	return *this;
}

bool ScalarConversion::is_char(void)
{
	if (this->_value.length() == 3 && this->_value[0] == '\'' && this->_value[2] == '\'')
	{
		return true;
	}
	return false;
}

bool ScalarConversion::is_int(void)
{
	for (size_t i = 0; i < this->_value.length(); i++)
	{
		if (!isdigit(this->_value[i]))
			return false;
	}
	return true;
}

bool ScalarConversion::is_float(void)
{
	for (size_t i = 0; i < this->_value.length(); i++)
	{
		if (this->_value[i] != '.' && this->_value[i] != 'f' && !isdigit(this->_value[i]))
			return false;
	}
	if (std::count(this->_value.begin(), this->_value.end(), 'f') != 1 || this->_value[this->_value.length() - 1] != 'f')
		return false;
	if (std::count(this->_value.begin(), this->_value.end(), '.') != 1)
		return false;
	if (this->_value[0] == '.' || this->_value[0] == 'f')
		return false;
	return true;
}

bool ScalarConversion::is_double(void)
{
	for (size_t i = 0; i < this->_value.length(); i++)
	{
		if (this->_value[i] != '.' && !isdigit(this->_value[i]))
			return false;
	}
	if (std::count(this->_value.begin(), this->_value.end(), '.') != 1)
		return false;
	if (this->_value[0] == '.' || this->_value[this->_value.length() - 1] == '.')
		return false;
	return true;
}

char ScalarConversion::convert_to_char(void) { return '0'; }

int ScalarConversion::convert_to_int(void) { return 0; }

float ScalarConversion::convert_to_float(void) { return 0.0f; }

double ScalarConversion::convert_to_double(void) { return 0.0; }
