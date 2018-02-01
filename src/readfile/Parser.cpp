//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include "Readfile.hpp"
#include "Error.hpp"

nts::Parser::Parser(int ac, char **av)
	: _fileName(av[1]), _ac(ac), _nbrInput(0)
{
		readFile();
		argsHandler(ac, av);
}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
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
	nts::IComponent *tmp;
	if (ac > 1)
	{
		nts::Parser kappa(ac, av);
/*			list = std::move(kappa.getList());
			for (auto i = list.begin(); i != list.end(); i++) {
			tmp = i->get();
			tmp->dump();
			}*/
	}
	else
		std::cout << "kappa ta pas mis d'arguments" << std::endl;
	return 0;
}
