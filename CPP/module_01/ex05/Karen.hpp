/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 15:00:27 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 10:08:37 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_H
# define KAREN_H

# include <string>
# include <iostream>

class Karen {
	public:
		Karen( void );
		~Karen( void );
		void complain( std::string level );
	
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

};

#endif // KAREN_H
	