/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 14:11:21 by tafocked          #+#    #+#             */
/*   Updated: 2025/05/14 14:59:04 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->i = 42;

	std::cout << "Original Data:" << std::endl;
	std::cout << "i: " << data->i << std::endl;
	std::cout << "Address: " << data << std::endl;

	uintptr_t raw = Serializer::serialize(data);

	std::cout << "\nSerialized Data:" << std::endl;
	std::cout << "Raw: " << raw << std::endl;
	std::cout << "Address: " << reinterpret_cast<Data*>(raw) << std::endl;

	Data *deserializedData = Serializer::deserialize(raw);

	std::cout << "\nDeserialized Data:" << std::endl;
	std::cout << "i: " << deserializedData->i << std::endl;
	std::cout << "Address: " << deserializedData << std::endl;

	delete data;

	return 0;
}