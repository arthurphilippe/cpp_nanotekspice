/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4013
*/

#include "components/Ref4013Comp.hpp"

nts::Ref4013Comp::Ref4013Comp(const std::string &name)
{
	_name.assign(name);
	_truthTable.push_back({TRUE, FALSE, FALSE, FALSE, FALSE});
	_truthTable.push_back({TRUE, TRUE, FALSE, FALSE, TRUE});
	_truthTable.push_back({FALSE, UNDEFINED, FALSE, FALSE, UNDEFINED});
	_truthTable.push_back({UNDEFINED, UNDEFINED, TRUE, FALSE, TRUE});
	_truthTable.push_back({UNDEFINED, UNDEFINED, FALSE, TRUE, FALSE});
	_truthTable.push_back({UNDEFINED, UNDEFINED, TRUE, TRUE, TRUE});
}

nts::Tristate nts::Ref4013Comp::flipFlop(Tristate clock, Tristate d,
	Tristate r, Tristate s)
{
	auto it = _truthTable.begin();

	while (it != _truthTable.end()) {
		if (r == it->r && s == it->s);
		++it;
	}
}

nts::Tristate nts::Ref4013Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
