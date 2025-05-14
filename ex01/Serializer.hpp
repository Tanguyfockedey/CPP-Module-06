/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:59:39 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/14 14:37:52 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer {
	private:
		// Default Constructor
		Serializer();
		Serializer(const Serializer &copy);

		// Destructor
		~Serializer();

		// Copy Assignment Operator
		Serializer &operator=(const Serializer &copy);

	public:
		// Static method to serialize a pointer to an integer
		static uintptr_t serialize(Data* ptr);

		// Static method to deserialize a pointer from an integer
		static Data* deserialize(uintptr_t raw);
};

