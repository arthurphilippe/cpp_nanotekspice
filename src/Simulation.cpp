/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#include <iostream>
#include "DefaultComponent.hpp"
#include "Simulation.hpp"

nts::Simulation::Simulation(std::list<std::unique_ptr<nts::IComponent>> &comps)
	: _components(&comps), _output()
{
	run();
	display();
}

nts::Simulation::~Simulation()
{}

void nts::Simulation::run(std::list<std::unique_ptr<nts::IComponent>> &comps)
{
	_components = &comps;
	run();
}

void nts::Simulation::run()
{
	auto		it = _components->begin();
	IComponent	*comp;

	_output.str("");
	while (it != _components->end()) {
		comp = it->get();
		if (comp->getType().compare("output") == 0)
			computeOutput(comp);
		++it;
	}
}

void nts::Simulation::display() const
{
	std::cout << _output.str();
}

void nts::Simulation::loop()
{
	while (true) {
		run();
	}
}

void nts::Simulation::computeOutput(IComponent *comp)
{
	auto state = comp->compute();

	_output << comp->getName() << "=";
	if (state == TRUE)
		_output << "1" << std::endl;
	else if (state == FALSE)
		_output << "0" << std::endl;
	else
		_output << "U" << std::endl;
}
