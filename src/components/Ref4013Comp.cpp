/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4013
*/

#include "components/Ref4013Comp.hpp"

nts::Ref4013Comp::Ref4013Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4013Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
