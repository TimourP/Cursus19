/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:17:45 by tpetit            #+#    #+#             */
/*   Updated: 2021/10/26 09:39:32 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie* zombie_horde = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombie_horde[i].name_zombie(name);
	}
	
	return (zombie_horde);
}