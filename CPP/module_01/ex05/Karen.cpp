/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:27 by tpetit            #+#    #+#             */
/*   Updated: 2022/03/01 15:48:21 by tpetit           ###   ########.fr       */
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

void Karen::complain( std::string level )
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
		std::cout << "I don't know this complain level..." << std::endl;
		return ;
	}
	(this->*(fctptr[complain_id]))();
}