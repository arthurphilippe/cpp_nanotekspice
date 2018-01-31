/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4008
*/

#include "components/Ref4008Comp.hpp"

nts::Ref4008Comp::Ref4008Comp(const std::string &name)
{
	_name.assign("4008");
	_name.assign(name);
}

nts::Tristate nts::Ref4008Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
