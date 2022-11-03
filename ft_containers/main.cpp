/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/03 15:38:44 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "containers/map.hpp"
#include <unistd.h>
#include <time.h>
#include <vector>
#include <list>
#include <map>

#define T1 int
#define T2 int

typedef ft::pair<const T1, T2> MT3;
typedef std::pair<const T1, T2> ST3;


int		main(void)
{
	srand(time(NULL));
	int t1, t2;
	ft::map<T1, T2> m;
	std::map<T1, T2> m2;
	for (int i = 0; i < 100000; i++) {
		t1 = rand() % 100000;
		t2 = rand() % 100000;
		m.insert(MT3(t1, t2));
		m2.insert(ST3(t1, t2));
	}

	std::cout << m.size() << std::endl;
	std::cout << m2.size() << std::endl;
	return (0);
}
