/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 2716
*/

#include "components/Ref2716Comp.hpp"

nts::Ref2716Comp::Ref2716Comp(const std::string &param)
{
	_name.assign("2716");
	(void) param;
}

nts::Tristate nts::Ref2716Comp::compute(std::size_t pin)
{
	(void) pin;
}
