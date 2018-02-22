/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Circuit
*/

#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "Parser.hpp"
#include "Error.hpp"
#include "Simulation.hpp"
#include "ComponentFactory.hpp"
#include "Circuit.hpp"

nts::Circuit::Circuit(int ac, char **av)
	: _name(av[1])
{
	Parser initialiser(_name, _components);
	ArgsHandler setter(ac, av, _components, initialiser.getInputCount());
}

nts::Circuit::~Circuit()
{}

nts::Circuit::Parser::Parser(const std::string &circuitName,
				componentList &components)
	: _circuitName(circuitName),
		_components(components),
		_inputCount(0)
{
	populateList();
}

void nts::Circuit::Parser::_updateMode(
	const std::string &line)
{
	if (line[0] == '.') {
		if (line == ".links:" || line == ".chipsets:")
			_currMode = line == ".links:" ? LINK : CHIPSET;
		else
			throw FileError(
				"Error : .links or .chipsets not present");

	}
}

void nts::Circuit::Parser::_parseLine(const std::string &line)
{
	int i = 0;
	std::string first;
	std::string value;

	if ((int) line.find("\t") < 1 && (int) line.find(" ") < 1)
		throw FileError("Please, check the configuration file");
	while (!(line[i] == ' ' || line[i] == '\0' || line[i] == '\t'))
		++i;
	first = line.substr(0, i);
	value = line.substr(i, line.length());
	value.erase(std::remove(value.begin(), value.end(), '\t'), value.end());
	value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
	if (_currMode == CHIPSET)
		_setChipset(first, value);
	else
		_parseLink(first, value);
}

void nts::Circuit::Parser::_parseLink(const std::string &a,
					const std::string &b)
{
	std::string a_chipset;
	std::string a_value;
	std::string b_chipset;
	std::string b_value;
	int i = 0;

	if ((i = a.find(":")) < 1)
		throw FileError("Error in the file links");
	a_chipset = a.substr(0, i);
	i += 1;
	a_value = a.substr(i, a.length());
	if (a_value.length() < 1)
		throw FileError(
			"Error in the file links : \
One of the chipset isn't linked to an pin");
	if ((i = b.find(":")) < 1)
		throw FileError("Error in the file links");
	b_chipset = b.substr(0, i);
	i += 1;
	b_value = b.substr(i, b.length());
	if (b_value.length() < 1)
		throw FileError("Error: links: \
One of the chipset isn't linked to an pin");
	_setLink(a_chipset, std::stoi(a_value),
			b_chipset, std::stoi(b_value));

}

void nts::Circuit::Parser::_setLink(const std::string &a, const int &a_value,
				const std::string &b, const int &b_value)
{
	if (!_isComponentInList(a) || !_isComponentInList(b))
		throw FileError("Error: _setLink: missing component");
	auto &tmp = _getComponent(a);
	auto &tmp_b = _getComponent(b);
	tmp->setLink(a_value, *tmp_b, b_value);
	tmp_b->setLink(b_value, *tmp, a_value);
}

std::unique_ptr<nts::IComponent> &nts::Circuit::Parser::_getComponent(
	const std::string &name)
{
	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_components.begin());
}

bool nts::Circuit::Parser::_isComponentInList(const std::string &name)
{
	bool found = false;

	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

void nts::Circuit::Parser::_setChipset(const std::string &type,
					const std::string &name)
{
	if (_isComponentInList(name))
		throw FileError("Error in the file, there are multiple re\
definitions of an input");
	if (name.length() < 1)
		throw FileError("Error in the file, check the chipset list");
	if ((int) name.find("(") > 1 && (int) name.find(")") > 1) {
		if (type.compare("2716") == 0)
			_setRom(type, name);
		else
			throw FileError("Error in the file, only the \
Rom can have a value");
		return ;
	} else if (((int) name.find("(") > 1 && (int) name.find(")") < 1) ||
			((int) name.find("(") < 1 && (int) name.find(")") > 1)){
		throw FileError("Error in the file, check the chipset list");
	} else {
		auto tmpComp = nts::ComponentFactory::createComponent(
				type, name);
		_components.push_back(std::move(tmpComp));
		if (type == "input") {
			++_inputCount;
		}
	}

}

void nts::Circuit::Parser::_setRom(const std::string &type, std::string name)
{
	std::string value;

	value = name.substr(name.find("("), name.length());
	name = name.substr(0, name.find("("));
	value.erase(std::remove(value.begin(), value.end(), '('), value.end());
	value.erase(std::remove(value.begin(), value.end(), ')'), value.end());
	auto comp = nts::ComponentFactory::createComponent(type, name, value);
	_components.push_back(std::move(comp));
}

void nts::Circuit::Parser::populateList()
{
	std::ifstream file(_circuitName.c_str());
	std::string line;

	if (!file.is_open()) {
		throw FileError("Received invalid file name in argument");
	}
	while (getline(file, line)) {
		line = line.substr(0, line.find("#"));
		if (line.size()) {
			_updateMode(line);
			_parseLine(line);
		}
	}
}

nts::Circuit::ArgsHandler::ArgsHandler(int ac, char **av,
					componentList &components, int inputNb)
	: _ac(ac), _av(av), _components(components), _inputCount(inputNb)
{
	_applyArguments();
}

void nts::Circuit::ArgsHandler::_applyArguments()
{
	int i(2);

	if (_ac < i + 1)
		throw FileError("Error : Please provide inputs's value");
	if (_validateArgsName() == true)
		while (_av[i]) {
			_applyArgument(_av[i]);
			++i;
		}
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		_validateInputNb(*i);
	}

}

bool nts::Circuit::ArgsHandler::_validateArgsName()
{
	int tokenIdx;
	int i(2);
	std::string tmp;

	while (_av[i]) {
		tmp = _av[i];
		tokenIdx = tmp.find("=");
		if (tokenIdx < 1)
			throw FileError("Error: Invalid Arguments");
		tmp = tmp.substr(0, tokenIdx);
		_vector.push_back(tmp);
		i++;
	}
	for (auto k = _vector.begin(); k != _vector.end(); k += 1) {
		if (count(_vector.begin(), _vector.end(), *k) != 1)
			throw FileError("Error : Check the argument \
there are multiple definitions of an input!");
	}
	return (true);
}

void nts::Circuit::ArgsHandler::_applyArgument(std::string arg)
{
	std::string chipset;
	std::string value;
	int tokenPlace;

	tokenPlace = arg.find("=");
	chipset = arg.substr(0, tokenPlace);
	value = arg.substr(tokenPlace + 1, arg.length());
	if (value.compare("1") != 0 && value.compare("0") != 0)
		throw FileError("Error: Arguments: invalid input value");
	if (_isComponentInList(chipset)) {
		auto &tmp = _getComponent(chipset);
		if (value == "0")
			tmp->compute(3);
		else
			tmp->compute(2);
	} else {
		throw FileError("Error: Arguments: invalid input name");
	}
}

bool nts::Circuit::ArgsHandler::_isComponentInList(const std::string &name)
{
	bool found = false;

	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

std::unique_ptr<nts::IComponent> &nts::Circuit::ArgsHandler::_getComponent(
	const std::string &name)
{
	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_components.begin());
}

bool nts::Circuit::ArgsHandler::_validateInputNb(const std::string &name)
{
	for (auto i = _vector.begin(); i != _vector.end(); i += 1) {
		if (*i == name) {
			if (!_getComponent(name)->getType().compare("input")) {
				_inputCount -= 1;
				return true;
			}
		}
	}
	throw FileError("Error: Arguments: input count wasn't met");
}
