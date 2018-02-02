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

	if (pin) {
		_state = link->_linked.compute(link->_pairedPin);
	}
	return _state;
}
