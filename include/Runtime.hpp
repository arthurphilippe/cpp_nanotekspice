//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// Runtime
//

#ifndef RUNTIME_HPP_
	# define RUNTIME_HPP_

#include <map>
#include "Readfile.hpp"
#include "Simulation.hpp"

namespace nts {
	class Runtime {
	public:
		Runtime(int ac, char **av);
		~Runtime() {}
		bool doCommand(std::string &command);
		bool run();
		void exitProgram();
		void findCommand(const std::string &str);
		typedef void (nts::Runtime::*RunFuncPtr)(void);
		std::map<std::string, RunFuncPtr> _map;
	private:
		nts::Parser _args;
		nts::Simulation _sim;
	};
}

#endif /* !RUNTIME_HPP_ */
