/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 08:49:01 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 09:34:05 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	const int	N = 42;
	Zombie* zombie_horde = zombieHorde(N, "AgentSmith");

	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].annonce();
	}

	delete [] zombie_horde;
	
	return (0);
}