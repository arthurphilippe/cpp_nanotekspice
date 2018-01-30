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

void nts::readfile::parseLine(std::string line, nts::readfile::ParseWork a)
{
	int i = 0;
	std::string first;
	std::string value;

	while (!(line[i] == ' ' || line[i] == '\0' || line[i] == '\t'))
		++i;
	first = line.substr(0, i);
	value = line.substr(i, line.length());
	value.erase(std::remove(value.begin(), value.end(), '\t'), value.end());
	value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
	(a == CHIPSET) ? setChipset(first, value) : setLink(first, value);
}

void nts::readfile::setChipset(std::string type, std::string name)
{

}

void nts::readfile::setLink(std::string a, std::string b)
{
	std::string a_chipset;
	std::string a_value;
	std::string b_chipset;
	std::string b_vblue;
	int i = 0;

	i = a.find(":");
	a_chipset = a.substr(0, i);
	i++;
	a_value = a.substr(i, a.length());
	std::cout << a_chipset << ":";
	std::cout << a_value << "\t";
//	std::cout << a << std::endl;
	i = 0;

	i = b.find(":");
	b_chipset = b.substr(0, i);
	i++;
	b_vblue = b.substr(i, b.length());
	std::cout << b_chipset << ":";
	std::cout << b_vblue << std::endl;
//	std::cout << b << std::endl;

}

void nts::readfile::checkLine(std::string line)
{
	static std::string temporary;

	if (line[0] == '.')
		temporary = line;

	else if (temporary.compare(".links:") == 0)
		parseLine(line, LINK);
	else if (temporary == ".chipsets:")
		parseLine(line, CHIPSET);
}

void nts::readfile::readFile(const std::string &file)
{
	std::ifstream fd(file.c_str());
	std::string line;

	if (fd.is_open() == false) {
		std::cerr << "Received invalid file in argument" << std::endl;
		throw;
	}
	while (getline(fd, line)) {
		line = line.substr(0, line.find("#"));
		if (line.size() != 0)
		checkLine(line);
	}
}
