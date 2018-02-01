/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4030
*/

#include "components/Ref4030Comp.hpp"
#include "LogicGates.hpp"

nts::Ref4030Comp::Ref4030Comp(const std::string &name)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4030Comp::compute(std::size_t pin)
{
	size_t pinA;
	size_t pinB;

	switch (pin) {
		case(3):
			pinA = 1;
			pinB = 2;
			break;
		case (4):
			pinA = 5;
			pinB = 6;
			break;
		case (10):
			pinA = 8;
			pinB = 9;
			break;
		case (11):
			pinA = 12;
			pinB = 13;
			break;
		default:
			return UNDEFINED;
	}
	auto a = getLinkByPin(pinA);
	auto b = getLinkByPin(pinB);
	return LogicGates::NANDGate(a, b);
}
