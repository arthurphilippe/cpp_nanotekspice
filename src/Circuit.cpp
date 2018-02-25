/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Circuit
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Parser.hpp"
#include "Error.hpp"
#include "Simulation.hpp"
#include "ComponentFactory.hpp"

nts::Circuit::Circuit(int ac, char **av)
	: _name(av[1]),
	_components(),
	_initialiser(_name, *this),
	_setter(ac, av, _components, _initialiser.getInputCount())
{}

nts::Circuit::~Circuit()
{}

void nts::Circuit::setInputCommand(std::string arg)
{
	_setter._applyArgument(arg);
}

void nts::Circuit::listDump() const
{
	for (auto i = _components.begin(); i != _components.end(); i++) {
		(*i)->dump();
	}
}

bool nts::Circuit::isComponentInList(const std::string &query)
{
	bool found = false;

	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == query)
			found = true;
	}
	return found;
}
