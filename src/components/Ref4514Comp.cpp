/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4514
*/

#include "components/Ref4514Comp.hpp"

nts::Ref4514Comp::Ref4514Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4514Comp::compute(std::size_t pin)
{
	(void) pin;
	return TRUE;
}
