/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** output
*/

#include <iostream>
#include "components/Output.hpp"

nts::Output::Output(const std::string &name)
	: _state(UNDEFINED)
{
	_name.assign(name);
	_type.assign("output");
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	auto link = _links.begin();

	if (pin && link != _links.end()) {
		_state = link->_linked.compute(link->_pairedPin);
	}
	return _state;
}

bool nts::Output::isValid() const noexcept
{
	auto it = _links.begin();

	return it != _links.end() ? true : false;
}
