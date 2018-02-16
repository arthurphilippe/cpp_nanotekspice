/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../include/DefaultComponent.hpp"
#include "../include/components/Clock.hpp"

Test(BasicTest, Clock) {
	auto clock = nts::ComponentFactory::createComponent("clock", "main");
	auto state = clock->compute(1);

	cr_assert(state == nts::TRUE);
}

Test(Flip, Clock) {
	auto clock = nts::ComponentFactory::createComponent("clock", "main");
	auto state = clock->compute(1);

	cr_assert(state == nts::TRUE);
	clock->compute(2);
	state = clock->compute(1);
	cr_assert(state == nts::FALSE);

	clock->compute(2);
	state = clock->compute(1);
	cr_assert(state == nts::TRUE);
}
