/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:16:51 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/30 14:41:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
public:
	Brain(void);
	~Brain(void);
	Brain(Brain const &copy);
	Brain &operator=(Brain const &rhs);

	std::string getIdea(int index) const;
	void haveIdea(std::string idea);

private:
	std::string _ideas[100];
	int _idea_index;
};

#endif // BRAIN_H
