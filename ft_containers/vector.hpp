/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:54:22 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/21 17:42:59 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H

# include <string>
# include <iostream>



namespace ft
{

	template <typename T>
	void print(T& toprint) {
		std::cout << toprint << std::endl;
	}

	template <class T, class Allocator = std::allocator<T> >
	class vector{

		typedef T								value_type;
		typedef Allocator						allocator_type;
		typedef typename allocator_type::reference		reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer 		pointer;
		// typename T iterator;
		// typename T const_iterator;
		// typename T reverse_iterator;
		// typename T const_reverse_iterator;
		typedef int								difference_type;
		typedef unsigned int					size_type;

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
					const allocator_type& alloc = allocator_type());


			vector (const vector& x) {};

			~vector(void) {
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
			};

			// Returns the number of elements in the vector.
			// Constant complexity because get size attribute
			size_type size() const {
				return this->_size;
			};

			// Returns the maximum number of elements that the vector can hold.
			// Constant complexity
			size_type max_size() const {
				return this->_max_size;
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
			value_type& at (size_type n);
			const value_type& at (size_type n) const;

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
			void swap (vector& x);

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
	