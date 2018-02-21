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

namespace nts {
	using componentList = std::vector<std::unique_ptr<IComponent>>;
	class Circuit;
}

class nts::Circuit {
public:
	Circuit(int ac, char **av);
	~Circuit();
private:
	class Parser;
	class ArgsHandler;
	std::string _name;
	componentList _components;
};

class nts::Circuit::Parser {
public:
	Parser(const std::string &circuitName, componentList &components)
		: _circuitName(circuitName),
		_components(components),
		_inputCount(0)
	{
		populateList();
	}
	~Parser() = delete;
	void populateList();
private:
	// TODO: rename those two
	enum Mode {
		CHIPSET,
		LINK
	};
	const std::string &_circuitName;
	componentList &_components;
	int _inputCount;
	Mode _currMode;
	void _updateMode(const std::string &line);
	void _parseLine(const std::string &line);
	void _setChipset(const std::string &type,
					const std::string &name);
	void _setLink(const std::string &a, const std::string &b);
	bool _isComponentInList(const std::string &name);
	void _setRom(const std::string &type, std::string name);
}

#endif /* !CIRCUIT_HPP_ */
