/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4069
*/

#include "components/Ref4069Comp.hpp"

nts::Ref4069Comp::Ref4069Comp(const std::string &name)
{
	_name.assign("4069");
	_name.assign(name);
}

nts::Tristate nts::Ref4069Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
