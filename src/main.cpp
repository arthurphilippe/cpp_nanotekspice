/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** main
*/

#include <iostream>
#include "readfile.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
		nts::readfile::readFile(av[1]);
	else
		std::cout << "kappa ta pas mis d'arguments" << std::endl;
}
