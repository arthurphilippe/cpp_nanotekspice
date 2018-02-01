/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4011
*/

#include "components/Ref4011Comp.hpp"

nts::Ref4011Comp::Ref4011Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4011Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
