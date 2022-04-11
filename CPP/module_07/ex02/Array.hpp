/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 14:10:11 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/11 13:48:01 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <string>
#include <iostream>

template <typename T>
class Array
{
public:
	Array(void);
	Array(unsigned int n);
	~Array(void);
	Array(Array const &copy);

	Array &operator=(Array const &rhs);
	T &operator[](size_t const index) const;
	size_t size(void) const;

private:
	size_t _size;
	T *_args;
};

template <typename T>
Array<T>::Array(void) : _size(0), _args(NULL){};

template <typename T>
Array<T>::~Array(void)
{
	delete this->_args;
};

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_args = new T[n]();
};

template <typename T>
Array<T>::Array(Array<T> const &copy) : _size(copy.size())
{
	this->_args = new T[copy.size()];
	for (size_t i = 0; i < copy.size(); i++)
	{
		this->_args[i] = copy[i];
	}
};

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	this->_size = rhs.size();
	for (size_t i = 0; i < rhs.size(); i++)
	{
		this->_args[i] = rhs[i];
	}
	return *this;
};

template <typename T>
T &Array<T>::operator[](size_t const index) const
{
	if (index >= this->size() || index < 0)
	{
		throw std::out_of_range("Index out of range");
	}
	return (this->_args[index]);
}

template <typename T>
size_t Array<T>::size(void) const
{
	return this->_size;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, Array<T> const &array)
{
	for (size_t i = 0; i < array.size(); i++)
		os << "array[" << i << "] => " << array[i] << std::endl;
	return (os);
}

#endif // ARRAY_H
