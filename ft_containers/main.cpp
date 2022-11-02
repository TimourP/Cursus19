/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 10:37:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/map.hpp"
#include <unistd.h>
#include <time.h>
#include <vector>


int main(void) {
	ft::map<int, int> map_crois;
	ft::map<int, int> map_dec;
	ft::pair<int, int> p(2, 3);
	ft::pair<int, int> p2(3, 3);
	map_crois.insert(p);
	map_crois.insert(p2);
	map_dec.insert(p);

	map_crois.swap(map_dec);

	map_crois.clear();

	map_crois.size();
	
	for (ft::map<int, int>::iterator it = map_crois.begin(); it != map_crois.end(); it++)
	{
		std::cout << (*it).first << std::endl;
	}
	return 0;
}