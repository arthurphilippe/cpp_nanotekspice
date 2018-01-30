//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <fstream>
#include "readfile.hpp"



void nts::readfile::checkLine(const std::string &line)
{
	static std::string temporary;

	if (line[0] == '.')
		temporary = line;
	else if (temporary.compare(".links:") == 0)
		std::cout << "I'm a fucking link mwahaha " << line << std::endl;
	else if (temporary == ".chipsets:")
		std::cout << "CHIPSETS ON THE BOARD " << line << std::endl;
}

void nts::readfile::readFile(std::string file)
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
