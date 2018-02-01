/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 2716
*/

#include "components/Ref2716Comp.hpp"

nts::Ref2716Comp::Ref2716Comp(const std::string &name, const std::string &param)
{
	_name.assign(name);
	(void) param;
}

nts::Tristate nts::Ref2716Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
