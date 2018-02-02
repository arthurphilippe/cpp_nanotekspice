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
      {
	      _map["exits"] = &Runtime::exitProgram;
      }
catch (const FileError &error)
{
        throw RuntimeError(error.getError());
}

void nts::Runtime::exitProgram()
{
	exit(0);
}

bool nts::Runtime::doCommand(std::string &command)
{
	if (command.length() > 0) {
		std::cout << "Received Command : " << command << std::endl;
		for (auto i = _map.begin(); i != _map.end(); i++) {
			std::cout << i->first << std::endl;
	
		}
	}
	return true;
}

bool nts::Runtime::run()
{
	std::string command;
	while (true)
	{
		std::cout << ">";
	        getline(std::cin, command);
		if (std::cin.eof()) {
			throw RuntimeError("E O F : End Of File Received");
			_map.clear();
		}
		doCommand(command);
	}
	return true;
}
