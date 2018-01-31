/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4081
*/

#include "components/Ref4081Comp.hpp"

nts::Ref4081Comp::Ref4081Comp(const std::string &name)
{
	_name.assign("4081");
	_name.assign(name);
}

nts::Tristate nts::Ref4081Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
