/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4040
*/

#include "components/Ref4040Comp.hpp"

nts::Ref4040Comp::Ref4040Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4040Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
