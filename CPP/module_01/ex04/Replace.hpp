/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:15:02 by tpetit            #+#    #+#             */
/*   Updated: 2021/11/16 10:08:50 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_H
# define REPLACE_H

# include <string>
# include <iostream>
# include <fstream>

class Replace {
	public:
		Replace( const char* file_name, const char* str1, const char* str2 );
		~Replace( void );

		bool	check_argv( void ) const;
		void	create_replace_file( void ) const;
	
	private:
		std::string _file_name;
		std::string _str1;
		std::string _str2;
		bool get_file_content( std::string& content ) const;

};

#endif // REPLACE_H
	