//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include "Readfile.hpp"
#include "Error.hpp"

void nts::readfile::parseLine(std::string line, nts::readfile::ParseWork a)
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
	try {
		(a == CHIPSET) ? setChipset(first, value) : setLink(first, value);
	} catch (const FileError &error) {
		throw error;
	}
}

void nts::readfile::setROM(std::string type, std::string name)
{
	std::string value;

	value = name.substr(name.find("("), name.length());
	value.erase(std::remove(value.begin(), value.end(), '('), value.end());
	value.erase(std::remove(value.begin(), value.end(), ')'), value.end());
}

void nts::readfile::setChipset(std::string type, std::string name)
{
	if ((int)name.find("(") > 1 && (int)name.find(")") > 1) {
		try { setROM(type, name);
		} catch (const FileError &error) {
			throw error;
		}
		return ;
	} else if (((int)name.find("(") > 1 && (int)name.find(")") < 1) ||
		   ((int)name.find("(") < 1 && (int)name.find(")") > 1)){
		throw FileError("Error in the file, check the chipset list");
	} else {

	}
}
void nts::readfile::setLink(std::string a, std::string b)
{
	std::string a_chipset;
	std::string a_value;
	std::string b_chipset;
	std::string b_value;
	int i = 0;

	if ((i = a.find(":")) < 1)
		throw FileError("Error in the file links");
	a_chipset = a.substr(0, i);
	i++;
	a_value = a.substr(i, a.length());
//	std::cout << a_chipset << ":";
//	std::cout << a_value << std::endl;
	if (a_value.length() < 1)
		throw FileError("Error in the file links : One of the chipset isn't linked to an pin");
//	std::cout << a << std::endl;
	i = 0;

	if ((i = b.find(":")) < 1)
		throw FileError("Error in the file links");
	b_chipset = b.substr(0, i);
	i++;
	b_value = b.substr(i, b.length());
	if (b_value.length() < 1)
		throw FileError("Error in the file links : One of the chipset isn't linked to an pin");

//	std::cout << b_chipset << ":";
//	std::cout << b_vblue << std::endl;
//	std::cout << b << std::endl;

}

void nts::readfile::checkLine(std::string line)
{
	static std::string temporary;

	try
	{
		if (line[0] == '.')
			temporary = line;
		else if (temporary.compare(".links:") == 0)
			parseLine(line, LINK);
		else if (temporary == ".chipsets:")
			parseLine(line, CHIPSET);
	}
	catch (const FileError &error)
	{
		throw error;
	}
}

void nts::readfile::readFile(const std::string &file)
{
	std::ifstream fd(file.c_str());
	std::string line;

	if (fd.is_open() == false) {
		throw FileError("Received invalid file in argument");
	}
	while (getline(fd, line)) {
		line = line.substr(0, line.find("#"));
		if (line.size() != 0)
			checkLine(line);
	}
}
