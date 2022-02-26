/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:07:01 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 10:59:40 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H
#define SCALARCONVERSION_H

#include <string>
#include <iostream>
#include <algorithm> //std::count
#include <math.h>	 // nan, inff, inf
#include <sstream>	 //stringstream
#include <limits.h>	 // maxint
#include <iomanip>	 // std::setprecision

class ScalarConversion
{
public:
	ScalarConversion(void);
	ScalarConversion(std::string const initial_value);
	~ScalarConversion(void);
	ScalarConversion(ScalarConversion const &copy);
	ScalarConversion &operator=(ScalarConversion const &rhs);

	bool is_char(void);
	bool is_int(void);
	bool is_float(void);
	bool is_double(void);

	operator char() const
	{
		char num;

		std::stringstream stream;
		stream << this->_value;
		stream >> num;
		return num;
	}

	operator int() const
	{
		int num;

		std::stringstream stream;
		stream << this->_value;
		stream >> num;
		return num;
	}

	operator float() const
	{
		float num;

		if (this->_value == "+inff")
			return (INFINITY);
		else if (this->_value == "-inff")
			return (-INFINITY);
		else if (this->_value == "nanf")
			return (NAN);
		std::stringstream stream;
		stream << this->_value;
		stream >> num;
		return num;
	}

	operator double() const
	{
		double num;

		if (this->_value == "+inf")
			return (INFINITY);
		else if (this->_value == "-inf")
			return (-INFINITY);
		else if (this->_value == "nan")
			return (NAN);
		std::stringstream stream;
		stream << this->_value;
		stream >> num;
		return num;
	}

private:
	std::string _value;
};

#endif // SCALARCONVERSION_H
