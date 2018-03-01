/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "ComponentFactory.hpp"
#include "../include/DefaultComponent.hpp"
#include "../include/components/Clock.hpp"

Test(BasicTestValue0, Clock) {
	auto clock = nts::ComponentFactory::createComponent("clock", "main");
	auto state = clock->compute(3);

	cr_assert(state == nts::FALSE);
}

Test(BasicTestValue1, Clock) {
	auto clock = nts::ComponentFactory::createComponent("clock", "main");
	auto state = clock->compute(2);

	cr_assert(state == nts::TRUE);
}


Test(Flip, Clock) {
	auto clock = nts::ComponentFactory::createComponent("clock", "main");
	auto state = clock->compute(2);

	cr_assert(state == nts::TRUE);
	state = clock->compute(4);
	cr_assert(state == nts::FALSE);
	state = clock->compute(4);
	cr_assert(state == nts::TRUE);
	state = clock->compute(4);
	cr_assert(state == nts::FALSE);
	state = clock->compute(4);
	cr_assert(state == nts::TRUE);
	state = clock->compute(4);
	cr_assert(state == nts::FALSE);
	state = clock->compute(4);
	cr_assert(state == nts::TRUE);
	state = clock->compute(4);
	cr_assert(state == nts::FALSE);
	state = clock->compute(4);
	cr_assert(state == nts::TRUE);
	state = clock->compute(4);
	cr_assert(state == nts::FALSE);
	state = clock->compute(4);
	cr_assert(state == nts::TRUE);

}
