/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/01 09:27:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/map.hpp"
#include <unistd.h>
#include <time.h>
#include <vector>


int main(void) {
	ft::map<int, int> my_map;
	ft::pair<int, int> p(2, 3);
	ft::pair<int, int> p2(3, 3);
	my_map.insert(p);
	my_map.insert(p2);
	
	for (ft::map<int, int>::iterator it = my_map.begin(); it != my_map.end(); it++)
	{
		std::cout << (*it).first << std::endl;
	}
	return 0;
}