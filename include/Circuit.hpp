/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
	#define CIRCUIT_HPP_

#include <vector>
#include <memory>
#include "DefaultComponent.hpp"
#include "IComponent.hpp"
#include "Parser.hpp"
#include "ArgsHandler.hpp"

namespace nts {
	class Circuit;
}

class nts::Circuit {
public:
	Circuit(int ac, char **av);
	~Circuit();
	componentList &getComponents()
	{
		return _components;
	}
	void setInputCommand(std::string arg);
	void listDump() const;
private:
	class Parser;
	class ArgsHandler;
private:
	std::string _name;
	nts::Parser _initialiser;
	nts::ArgsHandler _setter;
	componentList _components;
};

#endif /* !CIRCUIT_HPP_ */
