/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** tests
*/

#include <iostream>
#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "../include/IComponent.hpp"
#include "../include/DefaultComponent.hpp"
#include "../include/Simulation.hpp"
#include <criterion/logging.h>

using criterion::logging::info;

Test(Basic, Sim) {
	std::vector<std::unique_ptr<nts::IComponent>> list;

	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	cr_assert((led->compute() == nts::UNDEFINED));
	nts::Simulation sim(list);

	list.push_back(std::move(i1));
	list.push_back(std::move(i2));
	list.push_back(std::move(led));
	list.push_back(std::move(chipset));

	sim.run();
	// std::cout << sim.getBuffer().str();
	// std::cout << std::flush;
	list[0]->compute(2);
	list[1]->compute(2);
	cr_assert((sim.getBuffer().str().compare("LED=U\n") == 0));
	sim.run();
	// std::cout << sim.getBuffer().str();
	// std::cout << std::flush;
	cr_assert((sim.getBuffer().str().compare("LED=1\n") == 0));
}

Test(First, Sim) {
	std::vector<std::unique_ptr<nts::IComponent>> list;

	auto i1 = std::move(nts::DefaultComponent::createComponent("input", "i1"));
	auto i2 = std::move(nts::DefaultComponent::createComponent("input", "i2"));
	auto led = std::move(nts::DefaultComponent::createComponent("output", "LED"));
	auto chipset = std::move(nts::DefaultComponent::createComponent("4081", "chipset"));

	led->setLink(1, *chipset, 10);
	chipset->setLink(8, *i1, 1);
	chipset->setLink(9, *i2, 1);
	cr_assert((led->compute() == nts::UNDEFINED));

	list.push_back(std::move(i1));
	list.push_back(std::move(i2));
	list.push_back(std::move(led));
	list.push_back(std::move(chipset));
	list[0]->compute(2);
	list[1]->compute(2);

	nts::Simulation sim(list);
	cr_assert((sim.getBuffer().str().compare("LED=1\n") == 0));
}
