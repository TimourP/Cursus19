/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 16:38:57 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
	double first_value;
	if (argc != 2)
	{
		std::cout << "Usage: ./scalar_conversion arg1" << std::endl;
		return (-1);
	}
	std::string str_in = argv[1];
	ScalarConversion *conversion = new ScalarConversion(str_in);
	for (size_t i = 0; i < str_in.length(); i++)
	{
		if (!isprint(str_in[i]))
		{
			std::cout << "Error: a part of this argument is not displayable" << std::endl;
			return (-1);
		}
	}

	if (conversion->is_char())
		first_value = static_cast<char>(*conversion);
	else if (conversion->is_int())
		first_value = static_cast<int>(*conversion);
	else if (conversion->is_float())
		first_value = static_cast<float>(*conversion);
	else if (conversion->is_double())
		first_value = static_cast<double>(*conversion);

	// print char equivalent
	if (first_value >= 0 && first_value <= 255)
	{
		char c = static_cast<char>(first_value);
		if (isprint(first_value))
		{
			std::cout << "char: '" << c << "'" << std::endl;
		}
		else
		{
			std::cout << "char: Non displayable" << std::endl;
		}
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
	}

	// print int equivalent
	if (first_value >= INT32_MIN && first_value <= INT32_MAX)
	{
		std::cout << "int: " << static_cast<int>(first_value) << std::endl;
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
	}

	// print float and double equivalent
	if (static_cast<int>(first_value) == first_value)
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(first_value) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(first_value) << std::endl;
	}
	else
	{
		std::cout << "float: " << static_cast<float>(first_value) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(first_value) << std::endl;
	}

	return (0);
}