/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 15:43:09 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen( void ) {}

Karen::~Karen( void ) {}


void Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

enum ComplainLevel {DEBUG, INFO, WARNING, ERROR};

void Karen::complain( std::string level )
{
	const std::string ini = "DEBUG     INFO      WARNING   ERROR     ";
	if (ini.find(level) == std::string::npos)
	{
		std::cout << "Comments level are DEBUG, INFO, WARNING and ERROR." << " \"" << level << "\" is not in this list." << std::endl;
		return ;
	}
	ComplainLevel l = ComplainLevel(ini.find(level) / 10);

	switch (l)
	{
	case DEBUG:
		this->debug();
		break;
	case INFO:
		this->info();
		break;
	case WARNING:
		this->warning();
		break;
	case ERROR:
		this->error();
		break;
	default:
		break;
	}
}