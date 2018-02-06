/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** logicgates
*/

#include "LogicGates.hpp"

nts::Tristate nts::LogicGates::ANDGate(Tristate a, Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return (a && b) ? TRUE : FALSE;
}

nts::Tristate nts::LogicGates::NANDGate(Tristate a, Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return (a && b) ? FALSE : TRUE;
}

nts::Tristate nts::LogicGates::ORGate(Tristate a, Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return (a || b) ? TRUE : FALSE;
}

nts::Tristate nts::LogicGates::NORGate(Tristate a, Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return (a || b) ? FALSE : TRUE;
}

nts::Tristate nts::LogicGates::XORGate(Tristate a, Tristate b)
{
	if (a == UNDEFINED || b == UNDEFINED)
		return UNDEFINED;
	return (a ^ b) ? TRUE : FALSE;
}

nts::Tristate nts::LogicGates::NOTGate(Tristate a)
{
	if (a == UNDEFINED)
		return (UNDEFINED);
	return (a == FALSE) ? TRUE : FALSE;
}
