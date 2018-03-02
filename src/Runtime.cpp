//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Runtime functions
//

#include <iostream>
#include <unistd.h>
#include "IComponent.hpp"
#include "Runtime.hpp"
#include "Error.hpp"
#include "Simulation.hpp"

nts::Runtime::Runtime(int ac, char **av)
try : _state(RUN), _circuit(ac, av), _sim(_circuit.getComponents())
{
	_map["exit"] = std::bind(&Runtime::exitProgram, this);
	_map["display"] = std::bind(&Runtime::callDisplay, this);
	_map["dump"] = std::bind(&Runtime::callDump, this);
	_map["simulate"] = std::bind(&Runtime::callSimulate, this);
	_map["loop"] = std::bind(&Runtime::callLoop, this);
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

void nts::Runtime::callInputValueChanger(std::string &line) noexcept
{
	try {
		_circuit.setInputCommand(line.c_str());
	} catch (const FileError &error) {
		error.what();
	}
	_state = COMMAND_LAUNCHED;
}

void nts::Runtime::callDisplay() const
{
	_sim.display();
}

void nts::Runtime::callDump() const
{
	_circuit.listDump();
}

void nts::Runtime::exitProgram()
{
	_state = EXIT;
}

void nts::Runtime::findCommand(const std::string &str)
{
	RunFuncPtr commandFcnt;
	if (str.length() > 0 && _map.find(str) != _map.end()) {
		commandFcnt = _map[str];
		_state = COMMAND_LAUNCHED;
		commandFcnt();
	}
	else
		_state = UNKNOW_COMMAND;
	return;
}

bool nts::Runtime::doCommand(std::string &command) noexcept
{
	_state = RUN;
	if (command.length() > 0) {
		if ((int) command.find("=") > 0)
			callInputValueChanger(command);
		else
			findCommand(command);
	}
	return (_state == UNKNOW_COMMAND) ? (false) : (true);
}

bool nts::Runtime::run()
{
	std::string command;
	while (_state != EXIT)
	{
		std::cout << "> ";
		getline(std::cin, command);
		if (std::cin.eof())
			_state = EXIT;
		if (command.length() && !doCommand(command)) {
			std::cerr << "nanotekspice: command not found: ";
			std::cerr << command << std::endl;
		}
	}
	return true;
}
