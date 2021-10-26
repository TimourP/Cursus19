import os
import sys
import datetime

special_char_1 = "{"
special_char_2 = "}"

def return_class_h_string(class_name):
	d = datetime.datetime.now()
	stri = f"""/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {d.strftime("%Y/%m/%d %H:%M:%S")} by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:05:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef {class_name.upper()}_H
# define {class_name.upper()}_H

# include "string"
# include "iostream"

class {class_name} {special_char_1}
	public:
		{class_name}( void );
		~{class_name}( void );
	
	private:

{special_char_2};

#endif // {class_name.upper()}_H
	"""
	return stri


def return_class_cpp_string(class_name):
	d = datetime.datetime.now()
	stri = f"""/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: {d.strftime("%Y/%m/%d %H:%M:%S")} by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 14:05:03 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "{class_name}.hpp"

{class_name}::{class_name}( void ) {special_char_1}{special_char_2}

{class_name}::~{class_name}( void ) {special_char_1}{special_char_2}
	"""
	return stri

pwd = os.getcwd()
n = len(sys.argv)

if n != 2:
	print("Please enter the name of the class")
	exit(0)

print()


with open(sys.argv[1] + ".hpp", "w") as f:
	f.write(return_class_h_string(sys.argv[1]))

with open(sys.argv[1] + ".cpp", "w") as f:
	f.write(return_class_cpp_string(sys.argv[1]))