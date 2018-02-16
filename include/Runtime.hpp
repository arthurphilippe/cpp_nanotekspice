//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Runtime
//

#ifndef RUNTIME_HPP_
	#define RUNTIME_HPP_

#include <map>
#include <functional>
#include "Readfile.hpp"
#include "Simulation.hpp"

namespace nts {
	class Runtime {
	public:
		enum RunState {
			RUN,
			UNKNOW_COMMAND,
			COMMAND_LAUNCHED
		};
		Runtime(int ac, char **av);
		~Runtime();
		bool doCommand(std::string &command);
		bool run();
		void exitProgram();
		void callLoop();
		void callSimulate();
		void callDisplay();
		void callDump();
		void callInputValueChanger(std::string &line);
		void findCommand(const std::string &str);
		// typedef void (nts::Runtime::*RunFuncPtr)(void);
		typedef std::function<void(void)> RunFuncPtr;
		std::map<std::string, RunFuncPtr> _map;
	private:
		RunState _state;
		nts::Parser _args;
		nts::Simulation _sim;
	};
}

#endif /* !RUNTIME_HPP_ */
