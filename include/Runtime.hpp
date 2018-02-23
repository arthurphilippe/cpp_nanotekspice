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
#include "Simulation.hpp"
#include "Circuit.hpp"

namespace nts {
	class Runtime {
	public:
		enum RunState {
			RUN,
			UNKNOW_COMMAND,
			COMMAND_LAUNCHED,
			EXIT
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
		using RunFuncPtr = std::function<void(void)>;
		std::unordered_map<std::string, RunFuncPtr> _map;
	private:
		RunState _state;
		nts::Circuit _circuit;
		nts::Simulation _sim;
	};
}

#endif /* !RUNTIME_HPP_ */
