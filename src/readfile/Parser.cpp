//
// EPITECH PROJECT, 2018
// a
// File description:
// a
//

#include <iostream>
#include "Readfile.hpp"
#include "Error.hpp"
#include "Simulation.hpp"

nts::Parser::Parser(int ac, char **av)
	: _ac(ac), _nbrInput(0)
{
	if (ac > 1) {
		_fileName = av[1];
		readFile();
		argsHandler(ac, av);
		isValid();
	} else {
		throw FileError("print_usage");
	}
}

void nts::Parser::isValid() const
{
	for (auto i = _list.begin(); i != _list.end(); i++) {
		if (!(*i)->isValid())
			throw FileError("Error : Ouput not linked");
	}
}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}

void nts::Parser::listDump()
{
	for (auto i = _list.begin(); i != _list.end(); i++) {
		(*i)->dump();
	}
}

bool nts::Parser::isComponentInList(const std::string &name)
{
	bool found = false;

	for (auto i = _list.begin(); i != _list.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

std::unique_ptr<nts::IComponent> &nts::Parser::getComponent(
	const std::string &name)
{
	for (auto i = _list.begin(); i != _list.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_list.begin());
}

int parserTester(int ac, char **av)
{
	std::list<std::unique_ptr<nts::IComponent>> list;

	if (ac > 1)
	{
		nts::Parser kappa(ac, av);
		nts::Simulation(kappa.getList());
	}
	else
		throw FileError("print_usage");
	return 0;
}
