/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#include <iostream>
#include "components/False.hpp"

nts::False::False(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::False::compute(std::size_t pin)
{
	return (pin == 1) ? FALSE : UNDEFINED;
}
