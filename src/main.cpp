/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include "Error.hpp"
#include "Readfile.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		try
		{
			nts::readfile::readFile(av[1]);
		}
		catch (const FileError &error)
		{
			error.what();
		}
	}
	else
		std::cout << "kappa ta pas mis d'arguments" << std::endl;
}
