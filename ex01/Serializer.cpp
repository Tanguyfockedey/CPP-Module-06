/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:09:56 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/14 14:27:49 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor\n";
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
	std::cout << "Serializer copy\n";
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor\n";
}

Serializer &Serializer::operator=(const Serializer &copy)
{
	if (this != &copy)
		*this = copy;
	std::cout << "Serializer assignment\n";
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
