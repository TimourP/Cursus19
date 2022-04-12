/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:10:51 by tpetit            #+#    #+#             */
/*   Updated: 2022/04/12 11:49:54 by tpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		Span sp = Span(50);
		int arr[] = { 0, 10 };
		int n = sizeof(arr) / sizeof(arr[0]);
	
		std::vector<int> vect(arr, arr + n);
		sp.addNumber(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(50);
		int arr[] = { -10, 0, 10 };
		int n = sizeof(arr) / sizeof(arr[0]);
	
		std::vector<int> vect(arr, arr + n);
		sp.addNumber(vect.begin(), vect.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		Span sp_copy = Span(sp);
		std::cout << sp_copy.shortestSpan() << std::endl;
		std::cout << sp_copy.longestSpan() << std::endl;

		Span sp_asign = Span(sp);
		sp.addNumber(1000);
		std::cout << sp_asign.shortestSpan() << std::endl;
		std::cout << sp_asign.longestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	{
		Span sp = Span(3);
		
		try
		{
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		try
		{
			int arr[] = { 0, 10, 2, 3 };
			int n = sizeof(arr) / sizeof(arr[0]);
		
			std::vector<int> vect(arr, arr + n);
			sp.addNumber(vect.begin(), vect.end());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
		
	}
}