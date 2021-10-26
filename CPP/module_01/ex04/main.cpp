/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:44:53 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:43:07 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace [filename] [string1] [string2]" << std::endl;
		return (1);
	}

	Replace replace = Replace(argv[1], argv[2], argv[3]);
	if (replace.check_argv())
	{
		std::cout << "Str could not be empty" << std::endl;
		return (1);
	}

	replace.create_replace_file();
	
	return (0);
}