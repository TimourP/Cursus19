/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:27 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/01 15:51:41 by tpetit           ###   ########.fr       */
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

void Karen::complain_filter( std::string level )
{
	const	std::string complain[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	typedef void (Karen::*fc)( void );
	fc fctptr[4] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	int		complain_id = -1;

	for (size_t i = 0; i < 4; i++)
	{
		if (level == complain[i]) {
			complain_id = i;
			break ;
		}
	}
	if (complain_id < 0) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}
	for (; complain_id < 4; complain_id++)
	{
		(this->*(fctptr[complain_id]))();
	}
	
}