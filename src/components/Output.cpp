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
}

nts::Tristate nts::Output::compute(std::size_t pin)
{
	auto link = _links.begin();
	if (pin) {
		_state = link->_linked.compute(link->_pairedPin);
		std::cout << _name << "=";
		if (_state == TRUE)
			std::cout << "1" << std::endl;
		else if (_state == FALSE)
			std::cout << "0" << std::endl;
		else
			std::cout << "U" << std::endl;
	}
	return _state;
}
