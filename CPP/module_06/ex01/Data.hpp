/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:47:18 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/26 11:58:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <string>
#include <iostream>

class Data
{
public:
	Data(void);
	Data(std::string const name);
	~Data(void);
	Data(Data const &copy);
	Data &operator=(Data const &rhs);

	std::string getName(void) const;

private:
	std::string _name;
};

#endif // DATA_H
