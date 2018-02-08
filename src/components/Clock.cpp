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
	(void) pin;
	if (pin == 2)
		_state = (_state == TRUE) ? FALSE : TRUE;
	return _state;
}
