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
try : _state(RUN), _args(ac, av), _sim(_args.getList())
      {
	      _map["exite"] = &Runtime::exitProgram;
      }
catch (const FileError &error)
{
	throw RuntimeError(error.getError());
}

nts::Runtime::~Runtime()
{
}

void nts::Runtime::exitProgram()
{
	throw RuntimeError("exit");
}

void nts::Runtime::findCommand(const std::string &str)
{	
	RunFuncPtr test;
	if (str.length() > 0) {
	        test = _map[str];
		if (test != NULL)
			return (this->*test)();
	}
	return ;
}

bool nts::Runtime::doCommand(std::string &command)
{
	if (command.length() > 0) {
		std::cout << "Received Command : " << command << std::endl;
	        findCommand(command);
	}
	return true;
}

bool nts::Runtime::run()
{
	std::string command;
	while (_state == RUN)
	{
		std::cout << ">";
		getline(std::cin, command);
		if (command.compare("exit") == 0)
			return true;
		if (std::cin.eof()) {
			_map.clear();
			throw RuntimeError("E O F : End Of File Received");
		}
		doCommand(command);
	}
	return true;
}
