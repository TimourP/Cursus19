/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 10:54:22 by tpetit            #+#    #+#             */
/*   Updated: 2022/06/21 13:29:53 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef VECTOR_H
# define VECTOR_H

# include <string>
# include <iostream>

template <class T, class Allocator = std::allocator<T>>
class vector{

	typedef T								value_type;
	typedef Allocator						allocator_type;
	typedef allocator_type::reference		value_type;
	typedef allocator_type::const_reference	const_reference;
	typedef allocator_type::pointer 		pointer;
	// typedef T iterator;
	// typedef T const_iterator;
	// typedef T reverse_iterator;
	// typedef T const_reverse_iterator;
	typedef int								difference_type;
	typedef unsigned int					size_type;

	public:

		// empty constructor if allocator type is not given
		explicit vector (const allocator_type& alloc = allocator_type());


		explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type());


		template <class InputIterator>
        vector (InputIterator first, InputIterator last,
                const allocator_type& alloc = allocator_type());


		vector (const vector& x);

		~vector(void);

		// Returns the number of elements in the vector.
		// Constant complexity because get size attribute
		size_type size() const;

		// Returns the maximum number of elements that the vector can hold.
		// Constant complexity
		size_type max_size() const;

		// Resizes the container so that it contains n elements.
		// Linear complexity and double linear if realloc
		// If n < size => reduce to n first elem
		// If n > size => new elem as copy of val (can realloc if needed)
		void resize (size_type n, value_type val = value_type());

		// Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		// Constant complexity
		size_type capacity() const;

		// Returns whether the vector is empty (i.e. whether its size is 0).
		// Constant complexity
		bool empty() const;

		// Requests that the vector capacity be at least enough to contain n elements.
		// If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
		// If realloc linear complexity
		void reserve (size_type n);

		// Requests the container to reduce its capacity to fit its size.
		// Linear complexity if realloc
		void shrink_to_fit();

		// Returns a reference to the element at position n in the vector container.
		value_type& operator[] (size_type n);
		const value_type& operator[] (size_type n) const;

		// Returns a reference to the element at position n in the vector.
		// throw an out_of_range exception if n out of bound
		value_type& at (size_type n);
		const value_type& at (size_type n) const;

		// Returns a reference to the first element in the vector.
		// Undefind behavior if empty container
		value_type& front();
		const value_type& front() const;

	private:

		size_type	_size;
		size_type	_max_size;
		T*			_data[]

};


#endif // VECTOR_H
	