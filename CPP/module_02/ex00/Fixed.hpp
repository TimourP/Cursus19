/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 14:27:51 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 08:30:13 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include "string"
# include "iostream"

class Fixed {
	public:
		Fixed( void );
		Fixed( Fixed &to_copy );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		Fixed & operator=( Fixed const & rhs );
	
	private:
		int					_fixed;
		static const int	_fract_bit = 8;
};

#endif // FIXED_H
	