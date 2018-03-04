/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#include "components/False.hpp"
#include "Error.hpp"

nts::False::False(const std::string &name)
{
	_name.assign(name);
	_nb_pins = 1;
}

nts::Tristate nts::False::compute(std::size_t pin)
{
	if (pin != 1)
		throw RuntimeError("Requested pin is unkown");
	return FALSE;
}
