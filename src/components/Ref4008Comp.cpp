/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4008
*/

#include "components/Ref4008Comp.hpp"

nts::Ref4008Comp::Ref4008Comp(const std::string &name)
{
	_name.assign(name);
	_truthTable.push_back({FALSE, FALSE, FALSE, FALSE, FALSE});
	_truthTable.push_back({TRUE, FALSE, FALSE, FALSE, TRUE});
	_truthTable.push_back({FALSE, TRUE, FALSE, FALSE, TRUE});
	_truthTable.push_back({TRUE, TRUE, FALSE, TRUE, FALSE});
	_truthTable.push_back({FALSE, FALSE, TRUE, FALSE, TRUE});
	_truthTable.push_back({TRUE, FALSE, TRUE, TRUE, FALSE});
	_truthTable.push_back({FALSE, TRUE, TRUE, TRUE, FALSE});
	_truthTable.push_back({TRUE, TRUE, TRUE, TRUE, TRUE});

}

nts::Tristate
nts::Ref4008Comp::completeAdder(Tristate a, Tristate b, Tristate c,
				Tristate &co)
{
	auto it = _truthTable.begin();

	while (it != _truthTable.end()) {
		if (it->a == a && it->b == b && it->c == c) {
			co = it->carry;
			return (it->sum);
		}
		++it;
	}
	co = it->carry;
	return (UNDEFINED);
}

nts::Tristate nts::Ref4008Comp::compute(std::size_t pin)
{
	auto a1 = getLinkByPin(7);
	auto b1 = getLinkByPin(6);
	auto c1 = getLinkByPin(9);
	Tristate co;

	auto s = completeAdder(a1, b1, c1, co);
	if (pin == 10)
		return s;
	auto a2 = getLinkByPin(5);
	auto b2 = getLinkByPin(4);
	s = completeAdder(a2, b2, co, co);
	if (pin == 11)
		return s;
	auto a3 = getLinkByPin(3);
	auto b3 = getLinkByPin(2);
	s = completeAdder(a3, b3, co, co);
	if (pin == 12)
		return s;
	auto a4 = getLinkByPin(3);
	auto b4 = getLinkByPin(2);
	s = completeAdder(a4, b4, co, co);
	if (pin == 13)
		return s;
	return co;
}
