/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 17:01:19 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/map.hpp"
#include <unistd.h>
#include <time.h>
#include <vector>
#include <list>

#define T1 int
#define T2 int
typedef ft::pair<const T1, T2> T3;

int main(void) {
	ft::map<T1, T2> map_crois;
	ft::map<T1, T2> map_dec;

	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, 7));
	ft::map<T1, T2> mp(lst.begin(), lst.end());

	ft::map<T1, T2>::iterator e = mp.end();
	e--;
	std::cout << (*e).first << std::endl;

	//mp.erase((--mp.end())->first);

	return 0;
}