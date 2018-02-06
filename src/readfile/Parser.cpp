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
	} else {
		throw FileError("Error : False Arguments");
	}
}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}

void nts::Parser::listDump()
{
	nts::IComponent *tmp;

	for (auto i = _list.begin(); i != _list.end(); i++) {
		tmp = i->get();		
		tmp->dump();
	}
}

nts::IComponent *nts::Parser::getComponent(const std::string &name)
{
	nts::IComponent *tmp;

	for (auto i = _list.begin(); i != _list.end(); i++) {
		tmp = i->get();
		if (tmp->getName() == name)
			return tmp;
	}
	return nullptr;
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
