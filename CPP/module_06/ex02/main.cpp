/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/11 10:17:51 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	int num;
	std::srand(time(0));

	num = rand() % 3;
	switch (num)
	{
	case 0:
		std::cout << "Je genere un A" << std::endl;
		return new A();
	case 1:
		std::cout << "Je genere un B" << std::endl;
		return new B();
	case 2:
		std::cout << "Je genere un C" << std::endl;
		return new C();
	default:
		return NULL;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
	{
		std::cout << "Class A" << std::endl;
		return;
	}
	if (dynamic_cast<B *>(p))
	{
		std::cout << "Class B" << std::endl;
		return;
	}
	if (dynamic_cast<C *>(p))
	{
		std::cout << "Class C" << std::endl;
		return;
	}
	std::cout << "Unknown Class" << std::endl;
	return;
}

void identify(Base &p)
{
	try
	{
		A &new_a = dynamic_cast<A &>(p);
		(void)new_a;
		std::cout << "Class A" << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		try
		{
			B &new_b = dynamic_cast<B &>(p);
			(void)new_b;
			std::cout << "Class B" << std::endl;
		}
		catch (const std::bad_cast &e)
		{
			try
			{
				C &new_c = dynamic_cast<C &>(p);
				(void)new_c;
				std::cout << "Class C" << std::endl;
			}
			catch (const std::bad_cast &e)
			{
				std::cout << "Unknown Class" << std::endl;
				return;
			}
		}
	}
}

int main()
{
	Base *random = generate();

	identify(random);
	identify(*random);
	delete random;
}