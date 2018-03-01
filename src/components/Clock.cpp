/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** clock
*/

#include "components/Clock.hpp"

nts::Tristate nts::Clock::_state = TRUE;

nts::Clock::Clock(const std::string &name)
{
	_name.assign(name);
	_type.assign("clock");
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
	if (pin == 2)
		_state = TRUE;
	else if (pin == 3)
		_state = FALSE;
	else if (pin == 4)
		_state = (_state == TRUE) ? FALSE : TRUE;
	return _state;
}
