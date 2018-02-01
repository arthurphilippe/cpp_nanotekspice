/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** input
*/

#include "components/Input.hpp"

nts::Input::Input(const std::string &name)
	: _state(UNDEFINED)
{
	_name.assign(name);
	_type.assign("input");
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
	if (pin == 2)
		_state = TRUE;
	else if (pin == 3)
		_state = FALSE;
	return (pin == 1) ? _state : UNDEFINED;
}
