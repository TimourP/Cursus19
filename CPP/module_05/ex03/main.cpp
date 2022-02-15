/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:55:21 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/15 15:18:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main(void) {
	Intern *i = new Intern();
	Form *f;

	f = i->makeForm("presidential pardon", "mytarget");
	delete f;
	f = i->makeForm("robotomy request", "mytarget");
	delete f;
	f = i->makeForm("shrubbery creation", "mytarget");
	delete f;
	f = i->makeForm("shrubber creation", "mytarget");
	delete f;

	delete i;
	return 0;
}