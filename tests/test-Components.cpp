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

Test(Basic, InputOutput) {
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

Test(Basic, 4001) {
	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4001", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((led->compute() == nts::FALSE));
	i2->compute(3);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4011) {
	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4011", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((led->compute() == nts::TRUE));
	i2->compute(3);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4030) {
	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4030", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((led->compute() == nts::TRUE));
	i2->compute(3);
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(2);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4071) {
	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4071", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::TRUE));
	i1->compute(3);
	cr_assert((led->compute() == nts::TRUE));
	i2->compute(3);
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(2);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4081) {
	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::TRUE));
	i1->compute(3);
	cr_assert((led->compute() == nts::FALSE));
	i2->compute(3);
	cr_assert((led->compute() == nts::FALSE));
}

