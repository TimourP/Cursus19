/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:48:12 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/28 11:14:00 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

int main( void )
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Here is the string address: " << &str << std::endl;
	std::cout << "Here is the address stocked in the pointer: " << stringPTR << std::endl;
	std::cout << "Here is the address stocked in the referencd: " << &stringREF << std::endl;

	std::cout << "Here is the string: " << str << std::endl;
	std::cout << "Here is the value of the dereferenced pointer: " << *stringPTR << std::endl;
	std::cout << "Here is the value of the reference: " << stringREF << std::endl;
}