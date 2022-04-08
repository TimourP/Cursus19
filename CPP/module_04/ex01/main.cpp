/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:43:11 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/08 10:21:14 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main(void)
{
	{
		Cat cat = Cat();
		Dog dog = Dog();

		cat.getBrain()->haveIdea("Become a dog");
		dog.makeSound();

		Cat copy_cat = Cat(cat);

		std::cout << copy_cat.getBrain()->getIdea(0) << std::endl;
	}
	const int list_size = 10;
	Animal *animal_list[list_size];

	for (size_t i = 0; i < list_size; i++)
	{
		if (i % 2)
			animal_list[i] = new Cat();
		else
			animal_list[i] = new Dog();
	}

	for (size_t i = 0; i < list_size; i++)
	{
		delete animal_list[i];
	}
}