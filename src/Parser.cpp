/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Parser
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

nts::Parser::Parser(const std::string &circuitName,
				componentList &components)
	: _circuitName(circuitName),
		_components(components),
		_inputCount(0)
{
	populateList();
}

void nts::Parser::_updateMode(
	const std::string &line)
{
	if (line[0] == '.') {
		if (line == LINKS_SECT || line == CHIP_SECT)
			_currMode = line == LINKS_SECT ? LINK : CHIPSET;
		else
			throw FileError(ERR_SECTION);
	}
}

void nts::Parser::_parseLine(const std::string &line)
{
	int i = 0;
	std::string first;
	std::string value;

	if ((int) line.find("\t") < 1 && (int) line.find(" ") < 1)
		throw FileError(ERR_SYNTAX);
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

bool nts::Parser::_isModeTitleLine(const std::string &line)
{
	if (line[0] == '.')
		return true;
	return false;
}

void nts::Parser::_parseLink(const std::string &a,
					const std::string &b)
{
	std::string a_chipset;
	std::string a_value;
	std::string b_chipset;
	std::string b_value;
	int i = 0;

	if ((i = a.find(":")) < 1)
		throw FileError(ERR_LINKS);
	a_chipset = a.substr(0, i);
	i += 1;
	a_value = a.substr(i, a.length());
	if (a_value.length() < 1)
		throw FileError(ERR_LINKS_CHIPSET);
	if ((i = b.find(":")) < 1)
		throw FileError(ERR_LINKS);
	b_chipset = b.substr(0, i);
	i += 1;
	b_value = b.substr(i, b.length());
	if (b_value.length() < 1)
		throw FileError(ERR_LINKS_CHIPSET);
	_setLink(a_chipset, std::stoi(a_value),
			b_chipset, std::stoi(b_value));

}

void nts::Parser::_setLink(const std::string &a, const int &a_value,
				const std::string &b, const int &b_value)
{
	if (!_isComponentInList(a) || !_isComponentInList(b))
		throw FileError(ERR_UKN_COMP);
	auto &tmp = _getComponent(a);
	auto &tmp_b = _getComponent(b);
	tmp->setLink(a_value, *tmp_b, b_value);
	tmp_b->setLink(b_value, *tmp, a_value);
}

std::unique_ptr<nts::IComponent> &nts::Parser::_getComponent(
	const std::string &name)
{
	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_components.begin());
}

bool nts::Parser::_isComponentInList(const std::string &name)
{
	bool found = false;

	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

void nts::Parser::_setChipset(const std::string &type,
					const std::string &name)
{
	if (_isComponentInList(name))
		throw FileError(ERR_DUP_DEF);
	if (name.length() < 1)
		throw FileError(ERR_LIST);
	if ((int) name.find("(") > 1 && (int) name.find(")") > 1) {
		if (type == ROM_COMP)
			_setRom(type, name);
		else
			throw FileError(ERR_CMP_ARG);
		return ;
	} else if (((int) name.find("(") > 1 && (int) name.find(")") < 1) ||
			((int) name.find("(") < 1 && (int) name.find(")") > 1)){
		throw FileError(ERR_LIST);
	} else {
		auto tmpComp = nts::ComponentFactory::createComponent(
				type, name);
		_components.push_back(std::move(tmpComp));
		if (type == TYPE_INPUT || type == TYPE_CLOCK) {
			++_inputCount;
		}
	}

}

void nts::Parser::_setRom(const std::string &type, std::string name)
{
	std::string value;

	value = name.substr(name.find("("), name.length());
	name = name.substr(0, name.find("("));
	value.erase(std::remove(value.begin(), value.end(), '('), value.end());
	value.erase(std::remove(value.begin(), value.end(), ')'), value.end());
	auto comp = nts::ComponentFactory::createComponent(type, name, value);
	_components.push_back(std::move(comp));
}

void nts::Parser::populateList()
{
	std::ifstream file(_circuitName.c_str());
	std::string line;

	if (!file.is_open()) {
		throw FileError(ERR_FILE);
	}
	while (getline(file, line)) {
		line = line.substr(0, line.find("#"));
		if (line.size() && _isModeTitleLine(line))
			_updateMode(line);
		else if (line.size())
			_parseLine(line);
	}
}
