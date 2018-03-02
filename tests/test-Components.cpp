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
#include "ComponentFactory.hpp"

Test(Basic, InputOutput) {
	auto bouton = std::move(
		nts::ComponentFactory::createComponent("input", "bouton"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	led->setLink(1, *bouton, 1);
	bouton->setLink(1, *led, 1);

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

Test(Validity, InputOutput) {
	auto bouton = std::move(
		nts::ComponentFactory::createComponent("input", "bouton"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	cr_assert((!led->isValid()));
	cr_assert((bouton->isValid()));

	led->setLink(1, *bouton, 1);
	bouton->setLink(1, *led, 1);

	cr_assert((led->isValid()));
}

Test(Basic, 4001) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4001", "chipset"));

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
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4011", "chipset"));

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
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4030", "chipset"));

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
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4071", "chipset"));

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
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	led->compute();
	i1->compute(2);
	cr_assert((led->compute() == nts::UNDEFINED));
	i2->compute(2);
	led->compute();
	cr_assert((led->compute() == nts::TRUE));
	i1->compute(3);
	cr_assert((led->compute() == nts::FALSE));
	i2->compute(3);
	cr_assert((led->compute() == nts::FALSE));
}

Test(Basic, 4069) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4069", "chipset"));

	led->setLink(1, *chipset, 12);
	chipset->setLink(13, *i1, 1);
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4013) {
	auto clock = std::move(
		nts::ComponentFactory::createComponent("input", "clock"));
	auto set = std::move(
		nts::ComponentFactory::createComponent("input", "set"));
	auto reset = std::move(
		nts::ComponentFactory::createComponent("input", "reset"));
	auto data = std::move(
		nts::ComponentFactory::createComponent("input", "data"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4013", "chipset"));

	led->setLink(1, *chipset, 1);
	chipset->setLink(3, *clock, 1);
	chipset->setLink(4, *reset, 1);
	chipset->setLink(5, *data, 1);
	chipset->setLink(6, *set, 1);
	clock->compute(3);
	set->compute(3);
	reset->compute(3);
	data->compute(2);
	cr_assert((chipset->compute(1) == nts::UNDEFINED));
	clock->compute(2);
	cr_assert((chipset->compute(1) == nts::TRUE));
	clock->compute(3);
	chipset->compute(1);
	clock->compute(2);
	data->compute(3);
	cr_assert((chipset->compute(1) == nts::FALSE));
	data->compute(2);
	cr_assert((chipset->compute(1) == nts::FALSE));
	clock->compute(3);
	set->compute(2);
	cr_assert((chipset->compute(1) == nts::TRUE));
	set->compute(3);
	clock->compute(2);
	cr_assert((chipset->compute(1) == nts::TRUE));
	clock->compute(3);
	reset->compute(2);
	cr_assert((chipset->compute(1) == nts::FALSE));
}
