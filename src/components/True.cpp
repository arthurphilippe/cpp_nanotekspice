/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#include "components/True.hpp"
#include "Error.hpp"

nts::True::True(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::True::compute(std::size_t pin)
{
	if (pin != 1)
		throw RuntimeError("Requested pin is unkown");
	return (pin == 1) ? TRUE : UNDEFINED;
}
