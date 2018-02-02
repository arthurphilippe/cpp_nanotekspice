//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Runtime functions
//

#include <iostream>
#include "IComponent.hpp"
#include "Runtime.hpp"
#include "Error.hpp"

nts::Runtime::Runtime()
{
}

bool nts::Runtime::run()
{
	std::string tmp;

	while (true)
	{
		std::cout << ">";
		if (std::cin.eof())
			throw RuntimeError("kappa");
		getline(std::cin, tmp);
		std::cout << tmp << std::endl;
	}
	return true;
}
