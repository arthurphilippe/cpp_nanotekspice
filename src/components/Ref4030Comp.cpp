/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4030
*/

#include "components/Ref4030Comp.hpp"

nts::Ref4030Comp::Ref4030Comp()
{
	_name.assign("4030");
}

nts::Tristate nts::Ref4030Comp::compute(std::size_t pin)
{
	(void) pin;
}
