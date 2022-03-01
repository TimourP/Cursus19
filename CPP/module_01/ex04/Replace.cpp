/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:15:02 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/01 16:36:15 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace( const char* file_name, const char* str1, const char* str2 ) : _file_name(file_name), _str1(str1), _str2(str2) {}

Replace::~Replace( void ) {}

bool	Replace::check_argv( void ) const
{
	if (this->_str1 == "" || this->_str2 == "" || this->_file_name == "")
		return (1);
	return (0);
}

std::string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
	std::string tmp;

    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
		tmp = str.substr(0, start_pos);
		str = tmp + to + str.substr(start_pos + from.length(), str.length() - 1);
        start_pos += to.length();
    }
    return str;
}

void	Replace::create_replace_file( void ) const
{
	std::string content;

	if (this->get_file_content(content))
	{
		std::cout << "Please use a valid file" << std::endl;
		return ;
	}

	std::ofstream ofs(this->_file_name + ".replace");

	content = ReplaceAll(content, this->_str1, this->_str2);
	ofs << content;
	ofs.close();
}

bool Replace::get_file_content( std::string& content ) const
{
	std::ifstream input_file(this->_file_name);
	if (!input_file.good())
		return (1);
	input_file.seekg(0, std::ios::end);
	size_t size = input_file.tellg();
	std::string buffer(size, ' ');
	input_file.seekg(0);
	input_file.read(&buffer[0], size); 
	content = buffer;
	return (0);
}