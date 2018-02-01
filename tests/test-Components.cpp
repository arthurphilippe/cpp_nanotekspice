/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../include/DefaultComponent.hpp"
#include "../include/components/Output.hpp"
#include "../include/components/Input.hpp"

Test(Basic, Input) {
	auto bouton = std::move(nts::DefaultComponent::createComponent("input", "bouton"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));

	led->setLink(1, *bouton, 1);
	bouton->setLink(1, *led, 1);

	bouton->dump();
	led->dump();

	led->compute(1);
	bouton->compute(3);
	cr_assert(led->compute() == bouton->compute());
	cr_assert((bouton->compute() == nts::FALSE));

	led->compute(1);
	bouton->compute(2);
	cr_assert(led->compute() == bouton->compute());
	cr_assert((bouton->compute() == nts::TRUE));

	led->compute(1);
	bouton->compute(3);
	cr_assert(led->compute() == bouton->compute());
	cr_assert((bouton->compute() == nts::FALSE));

}
