/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4013
*/

#include "components/Ref4013Comp.hpp"

nts::Ref4013Comp::Ref4013Comp()
{
	_name.assign("4013");
}

nts::Tristate nts::Ref4013Comp::compute(std::size_t pin)
{
	(void) pin;
}
