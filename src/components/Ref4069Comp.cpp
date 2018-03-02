/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4069
*/

#include "components/Ref4069Comp.hpp"
#include "LogicGates.hpp"

nts::Ref4069Comp::Ref4069Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4069Comp::compute(std::size_t pin)
{
	size_t pinA;

	switch (pin) {
		case(2):
			pinA = 1;
			break;
		case (4):
			pinA = 3;
			break;
		case (6):
			pinA = 5;
			break;
		case (8):
			pinA = 9;
			break;
		case (10):
			pinA = 11;
			break;
		case (12):
			pinA = 13;
			break;
		default:
			return UNDEFINED;
	}
	auto a = getLinkByPin(pinA);
	return LogicGates::NOTGate(a);
}
