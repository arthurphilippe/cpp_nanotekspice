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
	componentList &getComponents()
	{
		return _components;
	}
	void _setInputCommand(std::string arg)
	{

	}
private:
	class Parser;
	class ArgsHandler;
private:
	nts::Circuit::Parser initialiser;
	nts::Circuit::ArgsHandler setter;
	std::string _name;
	componentList _components;
};

class nts::Circuit::Parser {
public:
	Parser(const std::string &circuitName, componentList &components);
	~Parser() {}
	void populateList();
	int getInputCount() const noexcept
	{
		return _inputCount;
	}
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
	void _setChipset(const std::string &type, const std::string &name);
	void _parseLink(const std::string &a, const std::string &b);
	void _setLink(const std::string &a, const int &a_value,
			const std::string &b, const int &b_value);
	std::unique_ptr<nts::IComponent> &_getComponent(
		const std::string &name);
	bool _isComponentInList(const std::string &name);
	void _setRom(const std::string &type, std::string name);
};

class nts::Circuit::ArgsHandler {
public:
	ArgsHandler(int ac, char **av, componentList &components, int inputNb);
	void _applyArgument(std::string arg);
private:
	int _ac;
	char **_av;
	componentList &_components;
	int _inputCount;
	std::vector<std::string> _vector;
	void _applyArguments();
	bool _validateArgsName();
	bool _isComponentInList(const std::string &name);
	std::unique_ptr<nts::IComponent> &_getComponent(
		const std::string &name);
	bool _validateInputNb(const std::string &name);
};

#endif /* !CIRCUIT_HPP_ */
