/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:48:12 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 10:00:45 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string"
#include "iostream"

int main( void )
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Here is the string: " << str << std::endl;
	std::cout << "Here is the value of the dereferenced pointer: " << *stringPTR << std::endl;
	std::cout << "Here is the value of the reference: " << stringREF << std::endl;

	std::cout << "You can edit value of the string directly by assigning a new value directly to that string: str = \"Hello World!\";" << std::endl;
	str = "Hello World!";
	std::cout << "New value of str: " << str << std::endl;

	std::cout << "You can change the value through the pointer: *stringPTR = \"What a cliché!\";" << std::endl;
	*stringPTR = "What a cliché!";
	std::cout << "New value of str: " << str << std::endl;

	std::cout << "You can change the value through the reference: stringREF = \"I am done with this test.\";" << std::endl;
	stringREF = "I am done with this test.";
	std::cout << "New value of str: " << str << std::endl;
}