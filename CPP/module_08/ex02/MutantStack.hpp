/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 09:52:05 by tpetit            #+#    #+#             */
/*   Updated: 2022/02/27 09:59:48 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <string>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : private virtual std::stack<T>
{
};

#endif // MUTANTSTACK_H