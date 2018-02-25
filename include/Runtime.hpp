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
		bool doCommand(std::string &command) noexcept;
		bool run() noexcept;
		void exitProgram();
		void callLoop();
		void callSimulate();
		void callDisplay() const;
		void callDump() const;
		void callInputValueChanger(std::string &line) noexcept;
		void findCommand(const std::string &str);
		using RunFuncPtr = std::function<void(void)>;
	private:
		RunState _state;
		nts::Circuit _circuit;
		nts::Simulation _sim;
		std::map<std::string, RunFuncPtr> _map;
	};
}

#endif /* !RUNTIME_HPP_ */
