/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#include <algorithm>
#include <iostream>
#include <memory>
#include <csignal>
#include "Error.hpp"
#include "DefaultComponent.hpp"
#include "Simulation.hpp"

bool nts::Simulation::_intSignalRecieved(false);

void nts::Simulation::sigIntHandler(int signum)
{
	(void) signum;
	_intSignalRecieved = true;
	std::cout << std::endl;
}

nts::Simulation::Simulation(std::vector<std::unique_ptr<nts::IComponent>> &comps)
	: _components(comps), _output()
{
	run();
	display();

	struct sigaction sa;
	sa.sa_handler = sigIntHandler;
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		throw RuntimeError("Error: Sigaction");
}

nts::Simulation::~Simulation()
{}

void nts::Simulation::run()
{
	auto it = _components.begin();

	_output.str("");
	while (it != _components.end()) {
		std::unique_ptr<IComponent> &comp = *it;
		if (comp->getType().compare("output") == 0)
			computeOutput(comp);
		++it;
	}
	for (auto i = _components.begin() ; i != _components.end(); ++i) {
		std::unique_ptr<IComponent> &comp = *i;
		if (comp->getType().compare("clock") == 0)
			comp->compute(2);
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
	_intSignalRecieved = false;
	while (!_intSignalRecieved)
		run();
}

void nts::Simulation::computeOutput(std::unique_ptr<IComponent> &comp)
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
