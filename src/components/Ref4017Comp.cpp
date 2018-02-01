/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4017
*/

#include "components/Ref4017Comp.hpp"

nts::Ref4017Comp::Ref4017Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4017Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
