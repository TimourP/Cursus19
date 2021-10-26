/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 15:52:06 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen( void ) {}

Karen::~Karen( void ) {}


void Karen::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl << "I just love it!" << std::endl;
	std::cout << std::endl;
}

void Karen::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money." << std::endl << "You don’t put enough!" << std::endl << "If you did I would not have to ask for it!" << std::endl;
	std::cout << std::endl;
}

void Karen::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl << "I’ve been coming here for years and you just started working here last month." << std::endl;
	std::cout << std::endl;
}

void Karen::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

enum ComplainLevel {DEBUG, INFO, WARNING, ERROR};

void Karen::complain_filter( std::string level )
{
	const std::string ini = "DEBUG     INFO      WARNING   ERROR     ";
	if (ini.find(level) == std::string::npos)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	ComplainLevel l = ComplainLevel(ini.find(level) / 10);

	switch (l)
	{
	case DEBUG:
		this->debug();
		this->info();
		this->warning();
		this->error();
		break;
	case INFO:
		this->info();
		this->warning();
		this->error();
		break;
	case WARNING:
		this->warning();
		this->error();
		break;
	case ERROR:
		this->error();
		break;
	default:
		break;
	}
}