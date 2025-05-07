/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:27:35 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/07 21:12:09 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "SC constructor\n";
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	*this = copy;
	std::cout << "SC copy\n";
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "SC destructor\n";
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "SC assignment\n";
	return (*this);
}

void ScalarConverter::convert(const std::string &str)
{
	size_t dot = str.find('.');
	size_t f = str.find('f');
	if (dot == std::string::npos)
	{
		if (isSpecial(str))
		{
			printSpecial(str);
			return;
		}
		if (isChar(str))
		{
			printChar(str);
			return;
		}
		if (isInt(str))
		{
			printInt(str);
			return;
		}
	}
	if (dot != std::string::npos)
	{
		if (isFloat(str))
		{
			if (f != std::string::npos)
			{
				printFloat(str);
				return;
			}
			printDouble(str);
			return;
		}
	}
	printInvalid(str);
}


bool isSpecial(const std::string &str)
{
	if (str == "nan" || str == "+inf" || str == "-inf" || str == "nanf" || str == "+inff" || str == "-inff")
		return (true);
	return (false);
}

bool isChar(const std::string &str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		return (true);
	return (false);
}

bool isInt(const std::string &str)
{
	int i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool isFloat(const std::string &str)
{
	int i = 0;
	int dot = str.find('.');
	int f = str.find('f');

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (i < dot)
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	i = dot + 1;
	while (i < f)
	{
		if (!isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

void printSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char:\timpossible" << std::endl; 
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\tnanf" << std::endl;
		std::cout << "double:\tnan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\t+inff" << std::endl;
		std::cout << "double:\t+inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char:\timpossible" << std::endl;
		std::cout << "int:\timpossible" << std::endl;
		std::cout << "float:\t-inff" << std::endl;
		std::cout << "double:\t-inf" << std::endl;
	}
}

void printChar(const std::string &str)
{
	char c = str[0];

	if (isprint(str[0]))
	{
		std::cout << "Char:\t'" << c << "'\n";
		std::cout << "Int:\t" << static_cast<int>(c) << "\n";
		std::cout << "Float:\t" << static_cast<float>(c) << ".0f\n";
		std::cout << "Double:\t" << static_cast<double>(c) << ".0\n";
	}
	else
	{
		std::cout << "Non displayable\n";
	}
}

void printInt(const std::string &str)
{
	(void)str;
}

void printFloat(const std::string &str)
{
	(void)str;
}

void printDouble(const std::string &str)
{
	(void)str;
}

void printInvalid(const std::string &str)
{
	(void)str;
}
