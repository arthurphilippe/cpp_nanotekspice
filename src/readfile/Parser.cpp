//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include "Readfile.hpp"
#include "Error.hpp"

nts::Parser::Parser(char **fileName)
	: _fileName(fileName[1])
{
	readFile();
}

nts::Parser::Parser(std::string fileName)
	: _fileName(fileName)
{}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}

int parserTester(int ac, char **av)
{
	std::list<std::unique_ptr<nts::IComponent>> list;
	nts::IComponent *tmp;
	if (ac > 1)
	{
		try
		{
			nts::Parser kappa(av);
			list = std::move(kappa.getList());
			for (auto i = list.begin(); i != list.end(); i++) {
				tmp = i->get();
				tmp->dump();
			}
		}
		catch (const FileError &error)
		{
			error.what();
		}
	}
	else
		std::cout << "kappa ta pas mis d'arguments" << std::endl;
	return 0;
}
