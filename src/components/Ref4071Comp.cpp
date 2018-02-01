/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4071
*/

#include "components/Ref4071Comp.hpp"

nts::Ref4071Comp::Ref4071Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4071Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
