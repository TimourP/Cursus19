/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:55:34 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/03 16:02:10 by tpetit           ###   ########.fr       */
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
	std::map<T1, T2> m;
	ft::map<T1, T2> m_m;
	int t1;
	int t2;
	for (int i = 0; i < 1000; i++) {
		t1 = rand() % 10000;
		t2 = rand() % 1000000;
		m.insert(ST3(t1, t2));
		m_m.insert(MT3(t1, t2));
	}
	for (size_t i = 0; i < m.size() * 10; i++) {
		t1 = rand() % 10000;
		m.erase(t1);
		m_m.erase(t1);
	}
	m.erase(++m.begin(), --m.end());
	m_m.erase(++m_m.begin(), --m_m.end());
	std::cout << (*(++m.begin())).first << std::endl;
	std::cout << (*(++m_m.begin())).first << std::endl;
	return 0;
}
