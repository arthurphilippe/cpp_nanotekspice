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

nts::Parser::Parser(int ac, char **av)
	: _ac(ac), _nbrInput(0)
{
	if (ac > 1) {
		_fileName = av[1];
		readFile();
		argsHandler(ac, av);
		isValid();
	} else {
		throw FileError("print_usage");
	}
}

void nts::Parser::isValid() const
{
	for (auto i = _list.begin(); i != _list.end(); ++i) {
		if (!(*i)->isValid())
			throw FileError("Error : Ouput not linked");
	}
}

std::vector<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}

void nts::Parser::listDump() const
{
	for (auto i = _list.begin(); i != _list.end(); i++) {
		(*i)->dump();
	}
}

bool nts::Parser::isComponentInList(const std::string &name)
{
	bool found = false;

	for (auto i = _list.begin(); i != _list.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

std::unique_ptr<nts::IComponent> &nts::Parser::getComponent(
	const std::string &name)
{
	for (auto i = _list.begin(); i != _list.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_list.begin());
}

int parserTester(int ac, char **av)
{
	std::vector<std::unique_ptr<nts::IComponent>> list;

	if (ac > 1)
	{
		nts::Parser kappa(ac, av);
		nts::Simulation(kappa.getList());
	}
	else
		throw FileError("print_usage");
	return 0;
}

/*
**	Parse the line given as parameter and run the according function
**	from the second argument (ENUM)
*/
void nts::Parser::parseLine(std::string line, nts::Parser::ParseWork mode)
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
	if (mode == CHIPSET)
		setChipset(first, value);
	else
		setLink(first, value);
}

/*
**	Parse the 'Rom' type Chipset
*/
void nts::Parser::setRom(const std::string &type, std::string &name)
{
	std::string value;

	value = name.substr(name.find("("), name.length());
	name = name.substr(0, name.find("("));
	value.erase(std::remove(value.begin(), value.end(), '('), value.end());
	value.erase(std::remove(value.begin(), value.end(), ')'), value.end());
	auto comp = nts::ComponentFactory::createComponent(type, name, value);
	_list.push_back(std::move(comp));
}

/*
**	Parse the Chipset information
*/
void nts::Parser::setChipset(const std::string &type, std::string &name)
{
	if (isComponentInList(name))
		throw FileError("Error in the file, there are multiple re\
definitions of an input");
	if (name.length() < 1)
		throw FileError("Error in the file, check the chipset list");
	if ((int)name.find("(") > 1 && (int)name.find(")") > 1) {
		if (type.compare("2716") == 0)
			setRom(type, name);
		else
			throw FileError("Error in the file, only the \
Rom can have a value");
		return ;
	} else if (((int)name.find("(") > 1 && (int)name.find(")") < 1) ||
			((int)name.find("(") < 1 && (int)name.find(")") > 1)){
		throw FileError("Error in the file, check the chipset list");
	} else {
		auto tmpComp = nts::ComponentFactory::createComponent(
				type, name);
		_list.push_back(std::move(tmpComp));
		if (type.compare("input") == 0) {
			++_nbrInput;
		}
	}
}

/*
**	Parse and link
*/
void nts::Parser::linkSetter(const std::string &a, const int &a_value,
				const std::string &b, const int &b_value)
{
	if (!isComponentInList(a) || !isComponentInList(b))
		throw FileError("Error in the linkSetter");
	auto &tmp = getComponent(a);
	auto &tmp_b = getComponent(b);
	tmp->setLink(a_value, *tmp_b, b_value);
	tmp_b->setLink(b_value, *tmp, a_value);
}

void nts::Parser::setLink(const std::string &a, const std::string &b)
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
		throw FileError("Error in the \
file links : One of the chipset isn't linked to an pin");
	linkSetter(a_chipset, std::stoi(a_value),
			b_chipset, std::stoi(b_value));
}

/*
**	Check line if it's a description (chipset or links)
**	and run the according function with the good param
*/
void nts::Parser::checkLine(std::string line)
{
	static std::string lastMode;

	if (line[0] == '.') {
		if (line == ".links:"
			|| line == ".chipsets:")
			lastMode = line;
		else
			throw FileError(
				"Error : .links or .chipsets not present");
	}
	else if (lastMode == ".links:")
		parseLine(line, LINK);
	else if (lastMode == ".chipsets:")
		parseLine(line, CHIPSET);
}

/*
**	Read the file from the filename given as argument
*/
void nts::Parser::readFile()
{
	std::ifstream fd(_fileName.c_str());
	std::string line;

	if (fd.is_open() == false) {
		throw FileError("Received invalid file name in argument");
	}
	while (getline(fd, line)) {
		line = line.substr(0, line.find("#"));
		if (line.size() != 0)
			checkLine(line);
	}
	if (_ac - 2 != _nbrInput)
		throw FileError("Error: difference in the number of inputs in\
 the arguments and configuration file");
}

bool nts::Parser::rmInputArgs(const std::string &name)
{
	for (auto i = _vector.begin(); i != _vector.end(); i += 1) {
		if (*i == name) {
			if (!getComponent(name)->getType().compare("input")) {
				_nbrInput -= 1;;
				return true;
			}
		}
	}
	throw FileError("Error : False Argument");
}

bool nts::Parser::argsNameChecker(char **av)
{
	int tokenPlace;
	int i = 2;
	std::string tmp;

	while (av[i]) {
		tmp = av[i];
		tokenPlace = tmp.find("=");
		if (tokenPlace < 1)
			throw FileError("Error : Check the argument !");
		tmp = tmp.substr(0, tokenPlace);
		_vector.push_back(tmp);
		i++;
	}
	for (auto k = _vector.begin(); k != _vector.end(); k += 1) {
		if (count(_vector.begin(), _vector.end(), *k) != 1)
			throw FileError("Error : Check the argument \
there are multiple definitions of an input !");
	}
	return (true);
}

void nts::Parser::argsChecker(const char *str)
{
	std::string arg(str);
	std::string chipset;
	std::string value;
	int tokenPlace;

	tokenPlace = arg.find("=");
	chipset = arg.substr(0, tokenPlace);
	value = arg.substr(tokenPlace + 1, arg.length());
	if (value.compare("1") != 0 && value.compare("0") != 0)
		throw FileError("Error : Check the value !");
	if (isComponentInList(chipset)) {
		auto &tmp = getComponent(chipset);
		if (value.compare("0") == 0)
			tmp->compute(3);
		else
			tmp->compute(2);
	} else {
		throw FileError("Error : Check the input name !");
	}
}

bool nts::Parser::argsHandler(int ac, char **av)
{
	int i = 2;

	if (ac < i + 1)
		throw FileError("Error : Please provide inputs's value");
	if (argsNameChecker(av) == true)
		while (av[i]) {
			argsChecker(av[i]);
			++i;
		}
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		rmInputArgs(*i);
	}
	return true;
}
