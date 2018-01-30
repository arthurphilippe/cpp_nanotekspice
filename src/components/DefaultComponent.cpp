/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** default
*/

#include <iostream>
#include "DefaultComponent.hpp"

void nts::DefaultComponent::dump() const
{
	std::cout << "dump is not yet implemented" << std::endl;
}

void nts::DefaultComponent::setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin)
{
	ComponentLink	newLink = {other, otherPin, pin};

	_links.push_back(newLink);
}
