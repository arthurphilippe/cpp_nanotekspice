/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#include <algorithm>
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

bool nts::Simulation::sortFunctor(const std::string &a, const std::string &b)
{
	std::string name_a;
	std::string name_b;
	int ret;

	name_a = a.substr(0, a.find("="));
	name_b = b.substr(0, b.find("="));
        ret = name_a.compare(name_b.c_str());
	return (ret < 0);
}

void nts::Simulation::printSortedOutput()
{
	std::vector<std::string> _vector;
	std::string tmp;
	std::stringstream ss;
	std::string tmp2;

	tmp2 = _output.str();
	ss << tmp2;
	while (getline(ss, tmp)) {
		_vector.push_back(tmp);
	}
        sort(_vector.begin(), _vector.end(), sortFunctor);
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		std::cout << *i << std::endl;
	}
}

void nts::Simulation::display()
{
        printSortedOutput();
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
