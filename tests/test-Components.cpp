/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** tests
*/

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "Error.hpp"
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

Test(Basic, True) {
	auto trueComp = std::move(
		nts::ComponentFactory::createComponent("true", "true"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	trueComp->setLink(1, *led, 1);
	led->setLink(1, *trueComp, 1);
	cr_assert(led->compute() == nts::TRUE);
}

Test(Basic, False) {
	auto falseComp = std::move(
		nts::ComponentFactory::createComponent("false", "false"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	falseComp->setLink(1, *led, 1);
	led->setLink(1, *falseComp, 1);
	cr_assert(led->compute() == nts::FALSE);
}

Test(Error, False) {
	auto falseComp = std::move(
		nts::ComponentFactory::createComponent("false", "false"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	cr_assert_throw(falseComp->setLink(2, *led, 1), FileError);
}

Test(Error, True) {
	auto trueComp = std::move(
		nts::ComponentFactory::createComponent("true", "true"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));

	cr_assert_throw(trueComp->setLink(2, *led, 1), FileError);
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
	chipset->setLink(1, *i1, 1);
	chipset->setLink(2, *i2, 1);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(6, *i2, 1);
	chipset->setLink(12, *i1, 1);
	chipset->setLink(13, *i2, 1);
	led->compute();
	cr_assert((chipset->compute(3) == nts::UNDEFINED));
	cr_assert((chipset->compute(4) == nts::UNDEFINED));
	cr_assert((chipset->compute(10) == nts::UNDEFINED));
	cr_assert((chipset->compute(11) == nts::UNDEFINED));
	cr_assert((led->compute() == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	led->compute();
	cr_assert((chipset->compute(3) == nts::FALSE));
	cr_assert((chipset->compute(4) == nts::FALSE));
	cr_assert((chipset->compute(10) == nts::FALSE));
	cr_assert((chipset->compute(11) == nts::FALSE));
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((chipset->compute(3) == nts::FALSE));
	cr_assert((chipset->compute(4) == nts::FALSE));
	cr_assert((chipset->compute(10) == nts::FALSE));
	cr_assert((chipset->compute(11) == nts::FALSE));
	cr_assert((led->compute() == nts::FALSE));
	i2->compute(3);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic, 4011) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4011", "chipset"));

	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	chipset->setLink(1, *i1, 1);
	chipset->setLink(2, *i2, 1);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(6, *i2, 1);
	chipset->setLink(12, *i1, 1);
	chipset->setLink(13, *i2, 1);
	cr_assert((chipset->compute(3) == nts::UNDEFINED));
	cr_assert((chipset->compute(4) == nts::UNDEFINED));
	cr_assert((chipset->compute(10) == nts::UNDEFINED));
	cr_assert((chipset->compute(11) == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	cr_assert((chipset->compute(3) == nts::FALSE));
	cr_assert((chipset->compute(4) == nts::FALSE));
	cr_assert((chipset->compute(10) == nts::FALSE));
	cr_assert((chipset->compute(11) == nts::FALSE));
	i1->compute(3);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
	i2->compute(3);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
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
	chipset->setLink(1, *i1, 1);
	chipset->setLink(2, *i2, 1);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(6, *i2, 1);
	chipset->setLink(12, *i1, 1);
	chipset->setLink(13, *i2, 1);
	led->compute();
	cr_assert((led->compute() == nts::UNDEFINED));
	cr_assert((chipset->compute(3) == nts::UNDEFINED));
	cr_assert((chipset->compute(4) == nts::UNDEFINED));
	cr_assert((chipset->compute(10) == nts::UNDEFINED));
	cr_assert((chipset->compute(11) == nts::UNDEFINED));
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
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4071", "chipset"));

	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	chipset->setLink(1, *i1, 1);
	chipset->setLink(2, *i2, 1);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(6, *i2, 1);
	chipset->setLink(12, *i1, 1);
	chipset->setLink(13, *i2, 1);
	cr_assert((chipset->compute(3) == nts::UNDEFINED));
	cr_assert((chipset->compute(4) == nts::UNDEFINED));
	cr_assert((chipset->compute(10) == nts::UNDEFINED));
	cr_assert((chipset->compute(11) == nts::UNDEFINED));
	i1->compute(2);
	i2->compute(2);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
	i1->compute(3);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
	i2->compute(3);
	cr_assert((chipset->compute(3) == nts::FALSE));
	cr_assert((chipset->compute(4) == nts::FALSE));
	cr_assert((chipset->compute(10) == nts::FALSE));
	cr_assert((chipset->compute(11) == nts::FALSE));
	i1->compute(2);
	cr_assert((chipset->compute(3) == nts::TRUE));
	cr_assert((chipset->compute(4) == nts::TRUE));
	cr_assert((chipset->compute(10) == nts::TRUE));
	cr_assert((chipset->compute(11) == nts::TRUE));
}

Test(Basic1, 4081) {
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

Test(Basic2, 4081) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 11);
	chipset->setLink(12, *i1, 1);
	chipset->setLink(13, *i2, 1);
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

Test(Basic3, 4081) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto i2 = std::move(
		nts::ComponentFactory::createComponent("input", "i2"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 4);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(6, *i2, 1);
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

Test(Udef, 4081) {
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4081", "chipset"));

	cr_assert((chipset->compute(42) == nts::UNDEFINED));
}


Test(Basic, 4069) {
	auto i1 = std::move(
		nts::ComponentFactory::createComponent("input", "i1"));
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4069", "chipset"));

	led->setLink(1, *chipset, 12);
	chipset->setLink(1, *i1, 1);
	chipset->setLink(3, *i1, 1);
	chipset->setLink(5, *i1, 1);
	chipset->setLink(9, *i1, 1);
	chipset->setLink(11, *i1, 1);
	chipset->setLink(13, *i1, 1);
	cr_assert((led->compute() == nts::UNDEFINED));
	cr_assert((chipset->compute(2) == nts::UNDEFINED));
	cr_assert((chipset->compute(4) == nts::UNDEFINED));
	cr_assert((chipset->compute(6) == nts::UNDEFINED));
	cr_assert((chipset->compute(8) == nts::UNDEFINED));
	cr_assert((chipset->compute(10) == nts::UNDEFINED));
	cr_assert((chipset->compute(12) == nts::UNDEFINED));
	i1->compute(2);
	cr_assert((led->compute() == nts::FALSE));
	i1->compute(3);
	cr_assert((led->compute() == nts::TRUE));
}

Test(Basic1, 4013) {
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
	chipset->compute(12);
}

Test(Udef, 4008) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto falseComp = std::move(
		nts::ComponentFactory::createComponent("false", "false"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4008", "chipset"));

	chipset->setLink(1, *falseComp, 1);
	chipset->setLink(2, *falseComp, 1);
	chipset->setLink(3, *falseComp, 1);
	chipset->setLink(4, *falseComp, 1);
	chipset->setLink(5, *falseComp, 1);
	chipset->setLink(6, *falseComp, 1);
	chipset->setLink(7, *falseComp, 1);
	chipset->setLink(8, *falseComp, 1);
	chipset->setLink(9, *falseComp, 1);
	chipset->setLink(9, *falseComp, 1);
	chipset->setLink(10, *falseComp, 1);
	chipset->setLink(11, *falseComp, 1);
	chipset->setLink(12, *falseComp, 1);
	chipset->setLink(13, *falseComp, 1);
	led->setLink(1, *chipset, 13);
	cr_assert((led->compute() == nts::FALSE));
}

Test(Udef, 4017) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4017", "chipset"));

	led->setLink(1, *chipset, 10);
	cr_assert((led->compute() == nts::UNDEFINED));
}

Test(Udef, 4094) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4094", "chipset"));

	led->setLink(1, *chipset, 10);
	cr_assert((led->compute() == nts::UNDEFINED));
}

Test(Udef, 4514) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4514", "chipset"));

	led->setLink(1, *chipset, 10);
	cr_assert((led->compute() == nts::UNDEFINED));
}

Test(Udef, 4801) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent("4801", "chipset"));

	led->setLink(1, *chipset, 10);
	cr_assert((led->compute() == nts::UNDEFINED));
}

Test(Udef, 2716) {
	auto led = std::move(
		nts::ComponentFactory::createComponent("output", "LED"));
	auto chipset = std::move(
		nts::ComponentFactory::createComponent(
			"2716", "chipset", "patate"));

	led->setLink(1, *chipset, 10);
	cr_assert((led->compute() == nts::UNDEFINED));
}
