/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 08:11:22 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConversion.hpp"

int main(int argc, char **argv)
{
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

	std::cout << "Is char " << conversion->is_char() << std::endl;
	std::cout << "Is int " << conversion->is_int() << std::endl;
	std::cout << "Is float " << conversion->is_float() << std::endl;
	std::cout << "Is double " << conversion->is_double() << std::endl;

	return (0);
}