/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4094
*/

#include "components/Ref4094Comp.hpp"

nts::Ref4094Comp::Ref4094Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4094Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
