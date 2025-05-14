/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:45 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/14 14:01:40 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter
{
	private:
		/* constr */
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		
		/* destr */
		~ScalarConverter();

		/* overload */
		ScalarConverter &operator=(const ScalarConverter &copy);

	public:
		static void convert(const std::string &string);
};

bool isSpecial(const std::string &str);
bool isChar(const std::string &str);
bool isInt(const std::string &str);
bool isFloat(const std::string &str);
void printSpecial(const std::string &str);
void printChar(const std::string &str);
void printInt(const std::string &str);
void printFloat(const std::string &str);
void printDouble(const std::string &str);
void printInvalid();
