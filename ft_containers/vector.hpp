/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:54:22 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/22 17:21:30 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H

# include <string>
# include <iostream>
# include <vector>
# include <iterator>
# include <stdexcept>
# include "random_access_iterator.hpp"


namespace ft
{

	template <typename T>
	void print(T& toprint) {
		std::cout << toprint << std::endl;
	}

	template <class T, class Allocator = std::allocator<T> >
	class vector{

		public:
			typedef T											value_type;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer 			pointer;
			typedef ft::random_access_iterator<T>				iterator;
			typedef ft::random_access_iterator<const T>			const_iterator;
			// typename T reverse_iterator;
			// typename T const_reverse_iterator;
			typedef int								difference_type;
			typedef size_t					size_type;

		public:

			// empty constructor if allocator type is not given
			explicit vector (const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _data(nullptr)
			{
			};


			explicit vector (size_type n, const value_type& val = value_type(),
					const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(n)
			{
				this->_data = this->_alloc.allocate(n);
				for (size_t i = 0; i < n; i++)
				{
					this->_alloc.construct(&this->_data[i], val);
				}
			};


			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0)
			{
				for (InputIterator i = first; i != last; i++)
					this->_size++;
				int i = 0;
				this->_data = this->_alloc.allocate(this->_size);
				this->_capacity = this->_size;
				while (first != last)
				{
					this->_alloc.construct(&this->_data[i], *first);
					i++;
					++first;
				}
			};

			vector (const vector& x)
			: _alloc(x._alloc), _size(0)
			{
				iterator begin = x.begin();
				iterator end = x.end();
				for (iterator i = begin; i != end; i++)
					this->_size++;
				int i = 0;
				this->_data = this->_alloc.allocate(this->_size);
				this->_capacity = this->_size;
				while (begin != end)
				{
					this->_alloc.construct(&this->_data[i], *begin);
					i++;
					++begin;
				}
			};

			~vector(void) {
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
			};

			iterator begin() const {
				return iterator(this->_data);
			};

			const_iterator cbegin() const {
				return iterator(this->_data);
			};

			iterator end() const {
				return iterator(this->_data + this->_size);
			};
			const_iterator cend() const {
				return iterator(this->_data + this->_size);
			};

			// Returns the number of elements in the vector.
			// Constant complexity because get size attribute
			size_type size() const {
				return this->_size;
			};

			// Returns the maximum number of elements that the vector can hold.
			// Constant complexity
			size_type max_size() const {
				return this->_alloc.max_size();
			};

			// Resizes the container so that it contains n elements.
			// Linear complexity and double linear if realloc
			// If n < size => reduce to n first elem
			// If n > size => new elem as copy of val (can realloc if needed)
			void resize (size_type n, value_type val = value_type()) {
				if (n < this->_size)
				{
					size_type i = n;
					while (++i <= this->_size)
						this->_alloc.destroy(&this->_data[i - 1]);
					this->_size = n;
				} else if (n > this->_capacity) {
					this->realloc(n);
				}
				if (n > this->_size)
				{
					while (this->_size < n)
					{
						this->_alloc.construct(&this->_data[this->_size], val);
						this->_size++;
					}
				}
			};

			// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
			// Constant complexity
			size_type capacity() const {
				return this->_capacity;
			};

			// Returns whether the vector is empty (i.e. whether its size is 0).
			// Constant complexity
			bool empty() const {
				return this->_size == 0;
			};

			// Requests that the vector capacity be at least enough to contain n elements.
			// If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
			// If realloc linear complexity
			void reserve (size_type n) {
				if (n > this->_capacity)
					this->realloc(n);
			};

			// Returns a reference to the element at position n in the vector container.
			value_type& operator[] (size_type n) {
				return this->_data[n];
			};

			const value_type& operator[] (size_type n) const {
				return this->_data[n];
			};

			// Returns a reference to the element at position n in the vector.
			// throw an out_of_range exception if n out of bound
			value_type& at (size_type n) {
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_data[n];
			};
			const value_type& at (size_type n) const {
				if (n >= this->_size)
					throw std::out_of_range("vector");
				return this->_data[n];
			};

			// Returns a reference to the first element in the vector.
			// Undefind behavior if empty container
			value_type& front() {
				return this->_data[0];
			};

			const value_type& front() const {
				return this->_data[0];
			};

			// Returns a reference to the last element in the vector.
			// Undefind behavior if empty container
			value_type& back() {
				return this->_data[this->_size - 1];
			};

			const value_type& back() const {
				return this->_data[this->_size - 1];
			};

			// Returns a direct pointer to the memory array used internally by the vector to store its owned elements.
			value_type* data() {
				return this->_data;
			};

			const value_type* data() const {
				return this->_data;
			};

			// Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last);

			void assign (size_type n, const value_type& val);

			// Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
			void push_back (const value_type& val) {
				if (this->_size < this->_capacity) {
					this->_alloc.construct(&this->_data[this->_size], val);
					this->_size++;
				} else {
					realloc_double();
					this->push_back(val);
				}
			};

			// Removes the last element in the vector, effectively reducing the container size by one.
			void pop_back() {
				if (!this->empty())
				{
					this->_size--;
					this->_alloc.destroy(&this->_data[this->_size]);
				}
			};

			// Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
			void swap (vector& x) {
				allocator_type	tmp_alloc;
				size_type		tmp_size;
				size_type		tmp_capacity;
				size_type		tmp_max_size;
				pointer			tmp_data;

				tmp_alloc = this->_alloc;
				tmp_size = this->_size;
				tmp_capacity = this->_capacity;
				tmp_max_size = this->_max_size;
				tmp_data = this->_data;

				this->_alloc = x._alloc;
				this->_size = x._size;
				this->_capacity = x._capacity;
				this->_max_size = x._max_size;
				this->_data = x._data;

				x._alloc = tmp_alloc;
				x._size = tmp_size;
				x._capacity = tmp_capacity;
				x._max_size = tmp_max_size;
				x._data = tmp_data;
			};

			// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
			void clear() {
				for (size_t i = 0; i < this->_size; i++)
				{
					this->_alloc.destroy(&this->_data[i]);
				}
				this->_size = 0;
			};

		private:

			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			size_type		_max_size;
			pointer			_data;

			void realloc_double(void) {
				if (this->_size == 0)
					this->realloc(1);
				else
					this->realloc(this->_size * 2);
			}

			void realloc(size_type new_size) {
				pointer tmp = this->_alloc.allocate(new_size);

				for (size_t i = 0; i < this->_size; i++)
				{
					if (i < new_size)
						this->_alloc.construct(&tmp[i], this->_data[i]);
					this->_alloc.destroy(&this->_data[i]);
				}
				this->_alloc.deallocate(this->_data, this->_capacity);
				this->_capacity = new_size;
				this->_data = tmp;
			}

	};
}

#endif // VECTOR_H
	