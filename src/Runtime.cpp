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
#include "Simulation.hpp"

nts::Runtime::Runtime(int ac, char **av)
try : _args(ac, av), _sim(_args.getList())
      {}
catch (const FileError &error)
{
        throw RuntimeError(error.getError());
}

bool nts::Runtime::doCommand(std::string &command)
{
	std::cout << "Received Command : " << command << std::endl;
	return true;
}

bool nts::Runtime::run()
{
	std::string command;
	while (true)
	{
		std::cout << ">";
	        getline(std::cin, command);
		if (std::cin.eof())
			throw RuntimeError("E O F : End Of File Received");
		doCommand(command);
	}
	return true;
}
