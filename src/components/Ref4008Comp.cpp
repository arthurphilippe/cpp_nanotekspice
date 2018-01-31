/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4008
*/

#include "components/Ref4008Comp.hpp"

nts::Ref4008Comp::Ref4008Comp()
{
	_name.assign("4008");
}

nts::Tristate nts::Ref4008Comp::compute(std::size_t pin)
{
	(void) pin;
}
