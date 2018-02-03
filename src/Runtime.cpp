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
	      _map["exit"] = &Runtime::exitProgram;
	      _map["display"] = &Runtime::callDisplay;
	      _map["dump"] = &Runtime::callDump;
	      _map["simulate"] = &Runtime::callSimulate;
	      _map["loop"] = &Runtime::callLoop;
      }
catch (const FileError &error)
{
	throw RuntimeError(error.getError());
}

nts::Runtime::~Runtime()
{
}

void nts::Runtime::callSimulate()
{
	_sim.run();
}

void nts::Runtime::callLoop()
{
	_sim.loop();
}

void nts::Runtime::callInputValueChanger(std::string &line)
{
	try {
		_args.argsChecker(line.c_str());
	} catch (const FileError &error) {
		error.what();
	}
}

void nts::Runtime::callDisplay()
{
	_sim.display();
}

void nts::Runtime::callDump()
{
	_args.listDump();
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
		if (test != NULL) {
			_state = COMMAND_LAUNCHED;
			return (this->*test)();
		}
	}
	return ;
}

bool nts::Runtime::doCommand(std::string &command)
{
	_state = RUN;
	if (command.length() > 0) {
		if ((int)command.find("=") > 0)
			callInputValueChanger(command);
		else
			findCommand(command);
	}
	return (_state == COMMAND_LAUNCHED) ? (true) : (false);
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
		if (!doCommand(command))
			std::cerr << "nanotekspice: command not found: "
				  << command << std::endl;
	}
	return true;
}
