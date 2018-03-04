/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** default
*/

#include <iostream>
#include "DefaultComponent.hpp"
#include "components/Ref2716Comp.hpp"
#include "components/Ref4001Comp.hpp"
#include "components/Ref4008Comp.hpp"
#include "components/Ref4011Comp.hpp"
#include "components/Ref4013Comp.hpp"
#include "components/Ref4017Comp.hpp"
#include "components/Ref4030Comp.hpp"
#include "components/Ref4040Comp.hpp"
#include "components/Ref4069Comp.hpp"
#include "components/Ref4071Comp.hpp"
#include "components/Ref4081Comp.hpp"
#include "components/Ref4094Comp.hpp"
#include "components/Ref4514Comp.hpp"
#include "components/Ref4801Comp.hpp"
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/False.hpp"
#include "components/True.hpp"
#include "components/Clock.hpp"
#include "Error.hpp"

void nts::DefaultComponent::dump() const noexcept
{
	auto link = _links.begin();

	std::cout << "links for " << _name << ":" << std::endl;
	while (link != _links.end()) {
		std::cout << " pin: " << link->_pin;
		std::cout << " --> " << link->_linked.getName();
		std::cout << ":" << link->_pairedPin << std::endl;
		link++;
	}
	std::cout << "end of links for " << _name << std::endl;
	std::cout << "---------------------" << std::endl;
}

void nts::DefaultComponent::setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin)
{
	ComponentLink newLink = {other, otherPin, pin, UNDEFINED};

	if (_nb_pins != 0 && pin > _nb_pins) {
		throw FileError("Linking to an unkown pin");
	}
	_links.push_back(newLink);
}

nts::Tristate nts::DefaultComponent::getLinkByPin(size_t pin) const noexcept
{
	auto link = _links.begin();

	while (link != _links.end()) {
		if (link->_pin == pin)
			return link->_linked.compute(
				link->_pairedPin);
		link++;
	}
	return UNDEFINED;
}

const std::string &nts::DefaultComponent::getName() const noexcept
{
	return _name;
}

const std::string &nts::DefaultComponent::getType() const noexcept
{
	return _type;
}

bool nts::DefaultComponent::isValid() const noexcept
{
	return true;
}
