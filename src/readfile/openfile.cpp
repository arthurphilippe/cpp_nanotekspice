//
// EPITECH PROJECT, 2018
// a
// File description:
// a
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <memory>
#include "ComponentFactory.hpp"
#include "Readfile.hpp"
#include "Error.hpp"

/*
**	Parse the line given as parameter and run the according function
**	from the second argument (ENUM)
*/
void nts::Parser::parseLine(std::string line, nts::Parser::ParseWork a)
{
	int i = 0;
	std::string first;
	std::string value;

	if ((int)line.find("\t") < 1 && (int)line.find(" ") < 1)
		throw FileError("Please, check the configuration file");
	while (!(line[i] == ' ' || line[i] == '\0' || line[i] == '\t'))
		++i;
	first = line.substr(0, i);
	value = line.substr(i, line.length());
	value.erase(std::remove(value.begin(), value.end(), '\t'), value.end());
	value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
	(a == CHIPSET) ? setChipset(first, value) : setLink(first, value);
}

/*
**	Parse the 'Rom' type Chipset
*/
void nts::Parser::setROM(const std::string &type, std::string &name)
{
	std::string value;

	value = name.substr(name.find("("), name.length());
	name = name.substr(0, name.find("("));
	value.erase(std::remove(value.begin(), value.end(), '('), value.end());
	value.erase(std::remove(value.begin(), value.end(), ')'), value.end());
	auto tmpComp = nts::ComponentFactory::createComponent(type, name,
								value);
	_list.push_back(std::move(tmpComp));
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
			setROM(type, name);
		else
			throw FileError("Error in the file, only the \
ROM can have a value");
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
**	Parse and
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
	static std::string temporary;

	if (line[0] == '.') {
		if (line.compare(".links:") == 0
			|| line.compare(".chipsets:") == 0)
			temporary = line;
		else
			throw FileError("Error : .links or .chipsets not present");
	}
	else if (temporary.compare(".links:") == 0)
		parseLine(line, LINK);
	else if (temporary == ".chipsets:")
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
		throw FileError("Error : Check the configuration file and\
 the arguments");
}
