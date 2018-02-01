/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include "Error.hpp"
#include "Readfile.hpp"
#include "DefaultComponent.hpp"

int main(int ac, char **av)
{
	std::list<std::unique_ptr<nts::IComponent>> list;
	nts::IComponent *tmp;
	if (ac > 1)
	{
		try
		{
			nts::Parser kappa(av[1]);

		        kappa.readFile(av[1]);
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

}
