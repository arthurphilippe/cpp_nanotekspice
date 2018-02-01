/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4801
*/

#include "components/Ref4801Comp.hpp"

nts::Ref4801Comp::Ref4801Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4801Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
