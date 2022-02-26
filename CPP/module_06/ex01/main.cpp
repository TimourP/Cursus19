/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:09:06 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 11:57:52 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	Data *elem = new Data("Hey je suis Jean");
	uintptr_t serialize_elem;

	std::cout << elem << std::endl;
	serialize_elem = serialize(elem);
	std::cout << serialize_elem << std::endl;
	delete deserialize(serialize_elem);
	return 0;
}