/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 12:48:35 by tpetit            #+#    #+#             */
/*   Updated: 2022/11/02 13:17:27 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_H
# define PAIR_H

namespace ft 
{
	template <class T1, class T2>
	class pair
	{

		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type first;
			second_type second;

			pair(void) : first(0), second(0) {};
			template<class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {};
			pair (const first_type& a, const second_type& b): first(a), second(b) {};
			
	};

	template <class T1, class T2>
  	pair<T1,T2> make_pair (T1 x, T2 y) {
		return pair<T1,T2>(x, y);
	};

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }
	
}

#endif