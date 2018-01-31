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
	if (ac > 1)
	{
		try
		{
			nts::Parser kappa(av[1]);
		        kappa.readFile(av[1]);
		}
		catch (const FileError &error)
		{
			error.what();
		}
	}
	else
		std::cout << "kappa ta pas mis d'arguments" << std::endl;
	std::unique_ptr<nts::IComponent> kappa = std::move(nts::DefaultComponent::createComponent("4001"));
	std::cout << "salut" << std::endl;
	kappa->dump();
}
