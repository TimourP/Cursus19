/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 15:32:16 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/map.hpp"
#include <unistd.h>
#include <time.h>
#include <vector>
#include <list>

#define T1 int
#define T2 std::string
typedef ft::pair<const T1, T2> T3;

int main(void) {
	ft::map<T1, T2> map_crois;
	ft::map<T1, T2> map_dec;

	std::list<T3> lst;
	unsigned int lst_size = 10;
	std::cout << std::string((lst_size - 0), 0 + 65) << std::endl;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	ft::map<T1, T2> mp(lst.begin(), lst.end());

	// for (ft::map<T1, T2>::iterator i = mp.begin(); i != mp.end(); i++)
	// {
	// 	std::cout << (*i).first << std::endl;
	// }
	

	return 0;
}