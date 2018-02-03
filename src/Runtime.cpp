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

void nts::Runtime::Call(const std::string &str)
{
	RunFuncPtr test = _map[str];
	return (this->*test)();
}

bool nts::Runtime::doCommand(std::string &command)
{
	if (command.length() > 0) {
		std::cout << "Received Command : " << command << std::endl;
		Call(command);
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
			_map.clear();
			throw RuntimeError("E O F : End Of File Received");
		}
		doCommand(command);
	}
	return true;
}
