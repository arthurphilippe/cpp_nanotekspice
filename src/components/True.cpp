/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#include "components/True.hpp"

nts::True::True(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::True::compute(std::size_t pin)
{
	(void) pin;
	return TRUE;
}
