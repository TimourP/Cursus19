/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConversion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:07:01 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 08:25:23 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_H
#define SCALARCONVERSION_H

#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

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

	char convert_to_char(void);
	int convert_to_int(void);
	float convert_to_float(void);
	double convert_to_double(void);

private:
	std::string _value;
};

#endif // SCALARCONVERSION_H
