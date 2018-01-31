/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../include/IComponent.hpp"
#include "../include/LogicGates.hpp"

Test(ANDGate, LogicGatesAssertions) {
	nts::Tristate a = nts::Tristate::TRUE;
	nts::Tristate b = nts::Tristate::TRUE;
	nts::Tristate c = nts::LogicGates::ANDGate(a, b);

	cr_assert((c == nts::Tristate::TRUE));

	a = nts::Tristate::FALSE;
	c = nts::LogicGates::ANDGate(a, b);
	cr_assert((c == nts::Tristate::FALSE));

	b = nts::Tristate::FALSE;
	c = nts::LogicGates::ANDGate(a, b);
	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::UNDEFINED;
	c = nts::LogicGates::ANDGate(a, b);
	cr_assert((c == nts::Tristate::UNDEFINED));
}

Test(NANDGate, LogicGatesAssertions) {
	nts::Tristate a = nts::Tristate::TRUE;
	nts::Tristate b = nts::Tristate::TRUE;
	nts::Tristate c = nts::LogicGates::NANDGate(a, b);

	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::FALSE;
	c = nts::LogicGates::NANDGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	b = nts::Tristate::FALSE;
	c = nts::LogicGates::NANDGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	a = nts::Tristate::UNDEFINED;
	c = nts::LogicGates::NANDGate(a, b);
	cr_assert((c == nts::Tristate::UNDEFINED));
}

Test(ORGate, LogicGatesAssertions) {
	nts::Tristate a = nts::Tristate::TRUE;
	nts::Tristate b = nts::Tristate::TRUE;
	nts::Tristate c = nts::LogicGates::ORGate(a, b);

	cr_assert((c == nts::Tristate::TRUE));

	a = nts::Tristate::FALSE;
	c = nts::LogicGates::ORGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	b = nts::Tristate::FALSE;
	c = nts::LogicGates::ORGate(a, b);
	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::UNDEFINED;
	c = nts::LogicGates::ORGate(a, b);
	cr_assert((c == nts::Tristate::UNDEFINED));
}

Test(NORGate, LogicGatesAssertions) {
	nts::Tristate a = nts::Tristate::TRUE;
	nts::Tristate b = nts::Tristate::TRUE;
	nts::Tristate c = nts::LogicGates::NORGate(a, b);

	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::FALSE;
	c = nts::LogicGates::NORGate(a, b);
	cr_assert((c == nts::Tristate::FALSE));

	b = nts::Tristate::FALSE;
	c = nts::LogicGates::NORGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	b = nts::Tristate::UNDEFINED;
	c = nts::LogicGates::NORGate(a, b);
	cr_assert((c == nts::Tristate::UNDEFINED));
}

Test(XORGate, LogicGatesAssertions) {
	nts::Tristate a = nts::Tristate::TRUE;
	nts::Tristate b = nts::Tristate::TRUE;
	nts::Tristate c = nts::LogicGates::XORGate(a, b);

	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::FALSE;
	c = nts::LogicGates::XORGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	b = nts::Tristate::FALSE;
	c = nts::LogicGates::XORGate(a, b);
	cr_assert((c == nts::Tristate::FALSE));

	a = nts::Tristate::TRUE;
	c = nts::LogicGates::XORGate(a, b);
	cr_assert((c == nts::Tristate::TRUE));

	a = nts::Tristate::UNDEFINED;
	c = nts::LogicGates::XORGate(a, b);
	cr_assert((c == nts::Tristate::UNDEFINED));
}
